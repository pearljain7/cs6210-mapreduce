#pragma once

#include "file_shard.h"
#include "mapreduce_spec.h"

class MapReduceImpl {
public:
  /* DON'T change this function declaration */
  bool run(const std::string& config_filename);

private:
  /* DON'T change the function declaration for these three functions */
  bool read_and_validate_spec(const std::string& config_filename);
  bool create_shards();
  bool run_master();

  MapReduceSpec mr_spec_;
  std::vector<FileShards> file_shards_;
};
