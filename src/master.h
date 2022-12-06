#pragma once

#include <chrono>
#include "mapreduce_spec.h"
#include "file_shard.h"
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc/grpc.h>
#include <grpc/support/log.h>
#include <memory>
#include <queue>
#include <thread>
#include <zconf.h>

#include "masterworker.pb.h"
#include "masterworker.grpc.pb.h"

#define TTL 10
#define CONNECTION_TTL 1000

struct RequestData {
    enum WorkType {
        MAP = 0,
        REDUCE = 1,
    };

    enum RequestStatus {
        NOT_STARTED = 0,
        PROCESSING = 1,
        FINISHED = 2
    };
};

struct WorkerData {
    enum WorkerStatus {
        BUSY = 1,
        IDLE = 2,
        DOWN = 3,
    };

    WorkerData(std::string worker_addr, int worker_id): ip_addr_(std::move(worker_addr)),
                                                                                status_(IDLE),
                                                                                worker_id(worker_id)
    {}

    std::string ip_addr_;
    WorkerStatus status_;
    int worker_id;
};


class WorkerClient {

    public:
        std::shared_ptr<grpc::Channel> channel;

    private:
        struct AsyncContextManager {
            grpc::ClientContext context;
            grpc::CompletionQueue cq;
            grpc::Status status;
        };

        struct MapAsyncContextManager: AsyncContextManager {
            masterworker::MapReply reply;
            std::unique_ptr<grpc::ClientAsyncResponseReader<masterworker::MapReply>> rpc;
        };

        struct ReduceAsyncContextManager: AsyncContextManager {
            masterworker::ReduceReply reply;
            std::unique_ptr<grpc::ClientAsyncResponseReader<masterworker::ReduceReply>> rpc;
        };

        std::unique_ptr<masterworker::WorkerService::Stub> stub_;
        std::shared_ptr<AsyncContextManager> context_manager;
        WorkerData worker_metadata;

    public:
        WorkerClient(WorkerData worker_data): worker_metadata(worker_data) {
            std::cout << "Master connecting to port: " << worker_data.ip_addr_ << std::endl;
            channel = grpc::CreateChannel(worker_data.ip_addr_, grpc::InsecureChannelCredentials());
            stub_ = masterworker::WorkerService::NewStub(channel);
        }

        void set_worker_status(WorkerData::WorkerStatus status) { 
            worker_metadata.status_ = status; 
        }

        WorkerData::WorkerStatus get_worker_status() { 
            return worker_metadata.status_; 
        }

        int get_worker_id() { 
            return worker_metadata.worker_id; 
        }

        masterworker::MapReply get_map_reply() {
            return std::static_pointer_cast<MapAsyncContextManager>(context_manager)->reply;
        }

        void SendMapRequestToWorker(const masterworker::MapRequest &request) {
            if (worker_metadata.status_ != WorkerData::IDLE) {
                std::cerr << "Sending request to idle worker is not recommended. Current status is: " << worker_metadata.status_ << std::endl;
                throw 1;
            }

            std::cout << "Sending Request: " << request.shard_id() << " for mapping to Worker: " << worker_metadata.worker_id << std::endl;

            worker_metadata.status_ = WorkerData::BUSY;
            context_manager = std::make_shared<MapAsyncContextManager>();
            std::chrono::system_clock::time_point deadline =
                    std::chrono::system_clock::now() + std::chrono::seconds(TTL);
            context_manager->context.set_deadline(deadline);

            std::shared_ptr<MapAsyncContextManager> map_context = std::static_pointer_cast<MapAsyncContextManager>(context_manager);
            map_context->rpc = stub_->PrepareAsyncRegisterMapService(&context_manager->context, request, &context_manager->cq);
            map_context->rpc->StartCall();
            map_context->rpc->Finish(&map_context->reply, &context_manager->status, (void*) 1);
        }

        void SendReduceRequestToWorker(const masterworker::ReduceRequest &request) {
            if (worker_metadata.status_ != WorkerData::IDLE) {
                std::cerr << "Sending request to idle worker is not recommended." << std::endl;
                throw 1;
            }

            std::cout << "Sending Request: " << request.reducer_id() << " for reducer to Worker: " << worker_metadata.worker_id << std::endl;

            worker_metadata.status_ = WorkerData::BUSY;
            context_manager = std::make_shared<ReduceAsyncContextManager>();

            std::chrono::system_clock::time_point deadline =
                    std::chrono::system_clock::now() + std::chrono::seconds(TTL);
            context_manager->context.set_deadline(deadline);

            std::shared_ptr<ReduceAsyncContextManager> reduce_context = std::static_pointer_cast<ReduceAsyncContextManager>(context_manager);
            reduce_context->rpc = stub_->PrepareAsyncRegisterReduceService(&context_manager->context, request, &context_manager->cq);
            reduce_context->rpc->StartCall();
            reduce_context->rpc->Finish(&reduce_context->reply, &context_manager->status, (void*) 1);
        }

        bool check_status() {
            std::cout << "Checking Status" << std::endl;
            void* got_tag;
            bool ok = false;
            std::chrono::system_clock::time_point delay = std::chrono::system_clock::now() + std::chrono::seconds(TTL);
            GPR_ASSERT(context_manager->cq.Next(&got_tag, &ok));
            GPR_ASSERT(got_tag == (void*)1);
            GPR_ASSERT(ok);
            if (context_manager->status.ok())
            {
                // set the status as idle indicating ready for another work on finishing current task.
                worker_metadata.status_ = WorkerData::IDLE;
                return true;
            } else {
                std::cout << "RPC failed" << std::endl;
                std::cout << context_manager->status.error_code() << ": " << context_manager->status.error_message() << std::endl;
                // set the status as down indicating worker did not return an appropriate response.
                worker_metadata.status_ = WorkerData::DOWN;
                return false;
            }

        }
};


/* CS6210_TASK: Handle all the bookkeeping that Master is supposed to do.
	This is probably the biggest task for this project, will test your understanding of map reduce */
class Master {

	public:
		/* DON'T change the function signature of this constructor. Send all info via MapReduceSpec struct to the Master in this constructor.*/
		Master(const MapReduceSpec&, const std::vector<FileShards>&);

		/* DON'T change this function's signature */
		bool run();

		bool task_all_finished(const std::vector<RequestData::RequestStatus>& status) {
		    for (auto stats : status) {
		        if (stats != RequestData::FINISHED) return false;
		    }
            return true;
		}

    private:
      
	    void assign_available_worker_to_jobs(RequestData::WorkType work_type);

		void check_reply_and_update_status(std::vector<RequestData::RequestStatus>& request_status, RequestData::WorkType work_type);

        void retest_connection(WorkerClient* worker);

	private:
		/* NOW you can add below, data members and member functions as per the need of your implementation*/
		std::vector<masterworker::MapRequest> map_requests_;
		std::vector<RequestData::RequestStatus> map_request_status_;

		std::vector<masterworker::ReduceRequest> reduce_requests_;
        std::vector<RequestData::RequestStatus> reduce_request_status_;

        std::queue<WorkerClient*> active_clients;

        std::vector<WorkerClient> worker_clients_;

        std::unordered_map<int, int> worker_job_tracker;
};


/* CS6210_TASK: This is all the information your master will get from the framework.
	You can populate your other class data members here if you want */
Master::Master(const MapReduceSpec& mr_spec, const std::vector<FileShards>& file_shards) {
    //TODO
    for (int worker_id = 0; worker_id < mr_spec.num_workers; worker_id++) {
        WorkerData cur_data = WorkerData(mr_spec.worker_ipaddr[worker_id], worker_id);
        worker_clients_.emplace_back(WorkerClient(cur_data));
    }

    // populate Map Requests
    for (int shard_id = 0; shard_id < file_shards.size(); shard_id++) {
        masterworker::MapRequest new_request;
        new_request.set_user_id(mr_spec.user_id);
        new_request.set_shard_id(shard_id);
        new_request.set_n_output(mr_spec.num_outputs);
        new_request.set_output_dir(mr_spec.output_dir);
        for (const ShardInfo& shard_info : file_shards[shard_id].shards) {
            masterworker::ShardInfo* new_shard_info = new_request.add_shards();
            new_shard_info->set_file_addr(shard_info.file_name);
            new_shard_info->set_start_offest(shard_info.start_offset);
            new_shard_info->set_end_offset(shard_info.end_offset);
        }
        map_requests_.emplace_back(new_request);
        map_request_status_.emplace_back(RequestData::NOT_STARTED);
    }

    // populate Reduce Requests
    for (int reduce_id = 0; reduce_id < mr_spec.num_outputs; reduce_id++) {
        masterworker::ReduceRequest new_reduce_request;
        new_reduce_request.set_output_dir(mr_spec.output_dir);
        new_reduce_request.set_user_id(mr_spec.user_id);
        new_reduce_request.set_reducer_id(reduce_id);

        reduce_requests_.emplace_back(new_reduce_request);
        reduce_request_status_.emplace_back(RequestData::NOT_STARTED);
    }
}



/* CS6210_TASK: Here you go. once this function is called you will complete whole map reduce task and return true if succeeded */
bool Master::run() {
	/*
		Assign tasks to workers and communicate their respective instructions (eg. userid etc). 
	*/
    std::cout << "Start map jobs.." << std::endl;
    while (!task_all_finished(map_request_status_)) {
        assign_available_worker_to_jobs(RequestData::MAP);
        check_reply_and_update_status(map_request_status_, RequestData::MAP);
    }

    std::cout << "Start reduce jobs.." << std::endl;
    while (!task_all_finished(reduce_request_status_)) {
        assign_available_worker_to_jobs(RequestData::REDUCE);
        check_reply_and_update_status(reduce_request_status_, RequestData::REDUCE);
    }

	return true;
}

void Master::assign_available_worker_to_jobs(RequestData::WorkType work_type) {
    for (auto& worker_client : worker_clients_) {
        if (worker_client.get_worker_status() != WorkerData::IDLE) 
            continue;

        auto &request_status = work_type == RequestData::MAP ? map_request_status_ : reduce_request_status_;

        for (int request_id = 0; request_id < request_status.size(); request_id++) {
            if (request_status[request_id] == RequestData::NOT_STARTED) {
                request_status[request_id] = RequestData::PROCESSING;
                worker_job_tracker[worker_client.get_worker_id()] = request_id;
                if (work_type == RequestData::MAP)
                    worker_client.SendMapRequestToWorker(map_requests_[request_id]);
                else
                    worker_client.SendReduceRequestToWorker(reduce_requests_[request_id]);

                active_clients.push(&worker_client);
                break;
            }
        }
    }
}

void Master::check_reply_and_update_status(std::vector<RequestData::RequestStatus>& request_status, RequestData::WorkType work_type) {
    while (!active_clients.empty()) {
        WorkerClient* current_worker = active_clients.front();
        active_clients.pop();

        bool done = current_worker->check_status();
        int worker_id = current_worker->get_worker_id();

        if (done) {
            std::cout << "Request is complete " << std::to_string(worker_job_tracker[worker_id]) << std::endl;
            request_status[worker_job_tracker[worker_id]] = RequestData::FINISHED;
            
            if (work_type == RequestData::REDUCE) 
                return;

            // Populate intermediate output in files for the map job.
            for (int reducer_id = 0; reducer_id < reduce_requests_.size(); reducer_id++) {
                reduce_requests_[reducer_id].add_intermediate_file_address(current_worker->get_map_reply().intermediate_file_location(reducer_id));
            }
        } else {
            // Worker is down or TTL of request is reached. Requeing the job.
            request_status[worker_job_tracker[worker_id]] = RequestData::NOT_STARTED;
            // Reconnect the worker client
            new std::thread(&Master::retest_connection, this, current_worker);
        }
    }
}

void Master::retest_connection(WorkerClient* worker) {
    std::cout << "Resetting connections" << std::endl;
    while (!worker->channel->WaitForConnected(std::chrono::system_clock::now() + std::chrono::seconds(CONNECTION_TTL)));
    worker->set_worker_status(WorkerData::IDLE);
   std::cout << "Worker: " << worker->get_worker_id() << " is open to take requests." << std::endl;
}