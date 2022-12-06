#pragma once

#include <vector>
#include "mapreduce_spec.h"

struct ShardInfo {
    std::string file_name;
    int start_offset;
    int end_offset;
};

/* CS6210_TASK: Create your own data structure here, where you can hold information about file splits,
     that your master would use for its own bookkeeping and to convey the tasks to the workers for mapping */
struct FileShards {
    std::vector<ShardInfo> shards;
};


/* CS6210_TASK: Create fileshards from the list of input files, map_kilobytes etc. using mr_spec you populated  */ 
inline bool shard_files(const MapReduceSpec& mr_spec, std::vector<FileShards>& shardedFiles) {
    // Using the sharding logic described in the paper
    int shard_size = mr_spec.map_kilobytes * 1024;
    int start_pos = 0, end_pos = 0, remaining = shard_size;
    FileShards curr_shards;
    // iterate through every file 
    for (auto &file_path : mr_spec.input_files) {
        std::ifstream infile(file_path, std::ifstream::binary);
        std::string line;
        // iterate through every line in the file
        while (getline(infile, line)) {
            int line_size = line.size() + 1; // since end position is excluded from the range
            end_pos += line_size;
            remaining -= line_size;
            if (remaining <= 0) {
                // Case when curr shard has reached maximum capacity. 
                curr_shards.shards.emplace_back(ShardInfo{file_path, start_pos, end_pos});
                shardedFiles.emplace_back(std::move(curr_shards));
                // end position of this shard is the start position of the next
                start_pos = end_pos;
                remaining = shard_size;
            }
        }
        infile.close();
        // Case where we have reached EOF but max shard size is not reached.
        if (remaining != shard_size) {
            curr_shards.shards.emplace_back(ShardInfo{file_path, start_pos, end_pos});
        }
        // reset positions to shard next file
        start_pos = 0;
        end_pos = 0;
    }
    // Add the last added shard 
    shardedFiles.emplace_back(std::move(curr_shards));
	return true;
}