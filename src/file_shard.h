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
struct FileShard {
     // TODO
     // Check in paper what this data structure is.
     // Read description about what the Sharding logic is.
    std::vector<ShardInfo> shards;
};


/* CS6210_TASK: Create fileshards from the list of input files, map_kilobytes etc. using mr_spec you populated  */ 
inline bool shard_files(const MapReduceSpec& mr_spec, std::vector<FileShard>& fileShards) {
  //TODO
    int shard_size = mr_spec.map_kilobytes * 1024;
    int start_pos = 0, end_pos = 0, remaining = shard_size;
    FileShard cur_shard;
    for (auto &file_path : mr_spec.input_files) {
        std::ifstream infile(file_path, std::ifstream::binary);
        std::string line;
        while (getline(infile, line)) {
            int real_size = line.size() + 1;
            end_pos += real_size;
            remaining -= real_size;
            if (remaining <= 0) {
                cur_shard.shards.emplace_back(ShardInfo{file_path, start_pos, end_pos});
                fileShards.emplace_back(std::move(cur_shard));
                start_pos = end_pos;
                // reset remaining byte to shard_size
                remaining = shard_size;
            }
        }

        infile.close();

        // if we reached the end of the file and there is still stuff remaining
        if (remaining != shard_size) {
            cur_shard.shards.emplace_back(ShardInfo{file_path, start_pos, end_pos});
        }

        // reset start position and end position because we have reached new file
        start_pos = 0;
        end_pos = 0;
    }
    // emplace the last shard
    fileShards.emplace_back(std::move(cur_shard));
	return true;
}