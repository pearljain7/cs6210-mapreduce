#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
#include <sys/stat.h>

/* CS6210_TASK: Create your data structure here for storing spec from the config file */
struct MapReduceSpec {
    // Fetches information from the config file which is to be passed to the Master. 
	// Framework: setup all infra that the Master requires to do it own job.
	// Master: Perform the map-reduce task, talk to workers and provide them work, communicate with workers. 
    int num_workers = 0;
    int map_kilobytes = 0;
    int num_outputs = 0;
    std::string output_dir = "./default/";
    std::string user_id = "default_user";
    std::vector<std::string> worker_ipaddr;
    std::vector<std::string> input_files;
};

/* CS6210_TASK: Populate MapReduceSpec data structure with the specification from the config file */
inline bool update_config_with_config_line(MapReduceSpec& mr_spec, const std::string& key, const std::string& value) {
    if (key == "n_workers") {
        mr_spec.num_workers = std::stoi(value);
    } else if (key == "worker_ipaddr_ports") {
        std::string addr;
        std::istringstream stream(value);
        while (getline(stream, addr, ',')) {
            mr_spec.worker_ipaddr.emplace_back(addr);
        }
    } else if (key == "input_files") {
        std::string filesaddr;
        std::istringstream stream(value);
        while (getline(stream, filesaddr, ',')) {
            mr_spec.input_files.emplace_back(filesaddr);
        }
    } else if (key == "output_dir") {
        mr_spec.output_dir = value;
    } else if (key == "n_output_files") {
        mr_spec.num_outputs = std::stoi(value);
    } else if (key == "map_kilobytes") {
        mr_spec.map_kilobytes = std::stoi(value);
    } else if (key == "user_id") {
        mr_spec.user_id = value;
    } else {
        std::cout << "Invalid key encountered: " << key << std::endl;
        return false;
    }
    return true;
}

/* CS6210_TASK: Populate MapReduceSpec data structure with the specification from the config file */
inline bool read_mr_spec_from_config_file(const std::string& config_filename, MapReduceSpec& mr_spec) {
    std::ifstream config_file_reader(config_filename, std::ifstream::in);
    std::string line, key, value;
    while (getline(config_file_reader, line)) {
        std::istringstream is_line(line);
        if (std::getline(is_line, key, '=') && std::getline(is_line, value)) {
            if (!update_config_with_config_line(mr_spec, key, value)) 
                return false;
        }
    }
    return true;
}


/* CS6210_TASK: validate the specification read from the config file */
inline bool validate_mr_spec(const MapReduceSpec& mr_spec) {
    if (mr_spec.num_workers == 0 || mr_spec.num_workers != mr_spec.worker_ipaddr.size()) {
        std::cerr << "Number of workers should be greater than 0 and should match the size of worker IP addresses provided." << std::endl;
        return false;
    }

    if (mr_spec.num_outputs <= 0) {
        std::cerr << "Output files should be greater than zero" << std::endl;
        return false;
    }

    if (mr_spec.map_kilobytes <= 0) {
        std::cerr << "Invalid shard size provided" << std::endl;
        return false;
    }

    if (mr_spec.user_id.empty()) {
        std::cerr << "Invalid user ID provided" << std::endl;
        return false;
    }

    for (auto& file_path : mr_spec.input_files) {
        std::ifstream file(file_path);
        if (file.fail()) {
            std::cerr << "Invalid input file path provided: " << file_path << std::endl;
            return false;
        }
    }
    struct stat buffer;
    if (stat(mr_spec.output_dir.c_str(), &buffer) != 0) {
        std::cerr << "Invalid output directory provided: " << mr_spec.output_dir << std::endl;
        return false;
    }
	return true;
}