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

    // Check in paper what this data structure is.
	// Collect information from the config file.
	// Store it in any format you want.
	// This is the only data struct that is passed on to the Master (along with the file shards).
	// Framework: setup all infra that the Master requires to do it own job.
	// Master: Perform the map-reduce task. Talk to worker and provide them work. communicate with workers. 
	// TODO
    int num_workers = 0;
    int map_kilobytes = 0;
    int num_outputs = 0;
    std::string output_dir = "";
    std::string user_id = "";
    std::vector<std::string> worker_ipaddr;
    std::vector<std::string> input_files;
};

/* CS6210_TASK: Populate MapReduceSpec data structure with the specification from the config file */
inline bool assign_key_value_to_config_(MapReduceSpec& mr_spec, const std::string& key, const std::string& value) {
  // Populate the struct here. 
	// TODO
    std::cout << "key: " << key << " Value: " << value << std::endl;
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
        std::cout << "key not exist: " << key << std::endl;
        return false;
    }
    return true;
}

/* CS6210_TASK: Populate MapReduceSpec data structure with the specification from the config file */
inline bool read_mr_spec_from_config_file(const std::string& config_filename, MapReduceSpec& mr_spec) {
  // Populate the struct here. 
	// TODO
    std::ifstream config_file_reader(config_filename, std::ifstream::in);
    std::string line, key, value;
    std::cout << "reading mr spec:" << std::endl;
    while (getline(config_file_reader, line)) {
        std::istringstream is_line(line);
        if (std::getline(is_line, key, '=') && std::getline(is_line, value)) {
            if (!assign_key_value_to_config_(mr_spec, key, value)) return false;
        }
    }
    return true;
}


/* CS6210_TASK: validate the specification read from the config file */
inline bool validate_mr_spec(const MapReduceSpec& mr_spec) {
  // validate inputs given by config file. (are files present, are the numbers okay)
	// TODO
    std::cout << "validating mr_spec" << std::endl;
    bool is_valid = true;
    if (mr_spec.num_workers == 0 || mr_spec.num_workers != mr_spec.worker_ipaddr.size()) {
        std::cerr << "Number of workers cannot be zero and should match the worker IP address." << std::endl;
        is_valid = false;
    }

    if (mr_spec.num_outputs <= 0) {
        std::cerr << "Output files have to be greater than zero" << std::endl;
        is_valid = false;
    }

    if (mr_spec.map_kilobytes <= 0) {
        std::cerr << "Shard size error" << std::endl;
        is_valid = false;
    }

    if (mr_spec.user_id.empty()) {
        std::cerr << "Please set user ID" << std::endl;
        is_valid = false;
    }

    // check for input path
    for (auto& file_path : mr_spec.input_files) {
        std::ifstream file(file_path);
        if (file.fail()) {
            std::cerr << "input file: " << file_path << " does not exist" << std::endl;
            is_valid = false;
        }
    }

    // check for output path
    struct stat buffer;
    if (stat(mr_spec.output_dir.c_str(), &buffer) != 0) {
        std::cerr << "Output path: " << mr_spec.output_dir << "does not exist" << std::endl;
        is_valid = false;
    }




	return is_valid;
}