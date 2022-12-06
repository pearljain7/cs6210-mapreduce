# cs6210Project4
MapReduce Infrastructure

## Project Instructionss

[Project Description](description.md)

[Code walk through](structure.md)

### How to setup the project  
Same as project 3 instructions

## Implementation Details

### file_shard.h
class `FileShards` holds all the shards corresponding to one file. It holds an array of shards. The `shard_files()` function divides the input files into shards based on the specified shared size. 

### mapreduce_specs.h
Fetches information from the config file which is to be passed to the Master.
It holds the following information:
* num_workers: Number of workers available to fo the map reduce task
* map_kilobytes: shard size
* num_outputs: output files number
* output_dir: output files directory
* user_id: CS6210
* worker_ipaddr: List of ip addresses of workers
* input_files: List of input files

### mr_tasks.h
* function `emit()` is responsible to ouput the results to files

### master.h
* Struct `RequestData` contains `WorkType` information {MAP or REDUCE} and `RequestStatus` {NOT_STARTED, PROCESSING, FINISHED}.
* Struct `WorkerData` contains worker's ip address, worker id, `WorkerStatus` information {BUSY, IDLE, DOWN} to indicate current status of the worker. 
* `Master` is responsible to assign tasks to worker threads and perform book keeping on the worker statuses. Ot keeps track of all running workers and communicates between mapper and reducer. The communication is done via gRPC using the file `masterworker.proto`.
* `WorkerClient` performs the job of establishing connection with the workers and process response (if success or failure).

### worker.h
* `run()` method in worker listens for a new map or reduce task provided by the master. 
Once it gets a new task, it processes it and communicate the completion to the Master via the specified protocol.
* `RegisterMapService()` is triggered for processing a map request. It calls the `get_mapper_from_task_factory()` to get the mapper implementation with mapping algorithm to run on the request.
* `RegisterReduceService()` is triggers for processing a reduce request. It calls the `get_reducer_from_task_factory()` which has the reducer implementation to run on the reduce request. 

### Handling slow worker

Using gRPC's `setDeadline()` function, we have set a TTL on the time a worker has to return a response. The gRPC call fails if the worker is too slow to regerate the response. In that case [Refer `check_reply_and_update_status()` in `master.h`], we flag the task as failed and re-assign it to another worker [Refer `run()` in `master.h`]
