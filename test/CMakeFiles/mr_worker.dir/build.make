# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sarah/Documents/AOS/project4/cs6210-mapreduce

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sarah/Documents/AOS/project4/cs6210-mapreduce

# Include any dependencies generated for this target.
include test/CMakeFiles/mr_worker.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/mr_worker.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/mr_worker.dir/flags.make

test/CMakeFiles/mr_worker.dir/user_tasks.cc.o: test/CMakeFiles/mr_worker.dir/flags.make
test/CMakeFiles/mr_worker.dir/user_tasks.cc.o: test/user_tasks.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sarah/Documents/AOS/project4/cs6210-mapreduce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/mr_worker.dir/user_tasks.cc.o"
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mr_worker.dir/user_tasks.cc.o -c /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test/user_tasks.cc

test/CMakeFiles/mr_worker.dir/user_tasks.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mr_worker.dir/user_tasks.cc.i"
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test/user_tasks.cc > CMakeFiles/mr_worker.dir/user_tasks.cc.i

test/CMakeFiles/mr_worker.dir/user_tasks.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mr_worker.dir/user_tasks.cc.s"
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test/user_tasks.cc -o CMakeFiles/mr_worker.dir/user_tasks.cc.s

# Object files for target mr_worker
mr_worker_OBJECTS = \
"CMakeFiles/mr_worker.dir/user_tasks.cc.o"

# External object files for target mr_worker
mr_worker_EXTERNAL_OBJECTS =

bin/mr_worker: test/CMakeFiles/mr_worker.dir/user_tasks.cc.o
bin/mr_worker: test/CMakeFiles/mr_worker.dir/build.make
bin/mr_worker: src/libmr_workerlib.a
bin/mr_worker: src/libp4protolib.a
bin/mr_worker: /lib/libgrpc++.a
bin/mr_worker: /usr/lib/libprotobuf.a
bin/mr_worker: /lib/libgrpc.a
bin/mr_worker: /lib/libz.a
bin/mr_worker: /lib/libcares.a
bin/mr_worker: /lib/libaddress_sorting.a
bin/mr_worker: /lib/libre2.a
bin/mr_worker: /lib/libupb.a
bin/mr_worker: /lib/libabsl_raw_hash_set.a
bin/mr_worker: /lib/libabsl_hashtablez_sampler.a
bin/mr_worker: /lib/libabsl_hash.a
bin/mr_worker: /lib/libabsl_city.a
bin/mr_worker: /lib/libabsl_low_level_hash.a
bin/mr_worker: /lib/libabsl_statusor.a
bin/mr_worker: /lib/libgpr.a
bin/mr_worker: /lib/libabsl_bad_variant_access.a
bin/mr_worker: /lib/libabsl_status.a
bin/mr_worker: /lib/libabsl_strerror.a
bin/mr_worker: /lib/libabsl_random_distributions.a
bin/mr_worker: /lib/libabsl_random_seed_sequences.a
bin/mr_worker: /lib/libabsl_random_internal_pool_urbg.a
bin/mr_worker: /lib/libabsl_random_internal_randen.a
bin/mr_worker: /lib/libabsl_random_internal_randen_hwaes.a
bin/mr_worker: /lib/libabsl_random_internal_randen_hwaes_impl.a
bin/mr_worker: /lib/libabsl_random_internal_randen_slow.a
bin/mr_worker: /lib/libabsl_random_internal_platform.a
bin/mr_worker: /lib/libabsl_random_internal_seed_material.a
bin/mr_worker: /lib/libabsl_random_seed_gen_exception.a
bin/mr_worker: /lib/libabsl_cord.a
bin/mr_worker: /lib/libabsl_bad_optional_access.a
bin/mr_worker: /lib/libabsl_cordz_info.a
bin/mr_worker: /lib/libabsl_cord_internal.a
bin/mr_worker: /lib/libabsl_cordz_functions.a
bin/mr_worker: /lib/libabsl_exponential_biased.a
bin/mr_worker: /lib/libabsl_cordz_handle.a
bin/mr_worker: /lib/libabsl_str_format_internal.a
bin/mr_worker: /lib/libabsl_synchronization.a
bin/mr_worker: /lib/libabsl_stacktrace.a
bin/mr_worker: /lib/libabsl_symbolize.a
bin/mr_worker: /lib/libabsl_debugging_internal.a
bin/mr_worker: /lib/libabsl_demangle_internal.a
bin/mr_worker: /lib/libabsl_graphcycles_internal.a
bin/mr_worker: /lib/libabsl_malloc_internal.a
bin/mr_worker: /lib/libabsl_time.a
bin/mr_worker: /lib/libabsl_strings.a
bin/mr_worker: /lib/libabsl_throw_delegate.a
bin/mr_worker: /lib/libabsl_int128.a
bin/mr_worker: /lib/libabsl_strings_internal.a
bin/mr_worker: /lib/libabsl_base.a
bin/mr_worker: /lib/libabsl_spinlock_wait.a
bin/mr_worker: /lib/libabsl_raw_logging_internal.a
bin/mr_worker: /lib/libabsl_log_severity.a
bin/mr_worker: /lib/libabsl_civil_time.a
bin/mr_worker: /lib/libabsl_time_zone.a
bin/mr_worker: /lib/libssl.a
bin/mr_worker: /lib/libcrypto.a
bin/mr_worker: test/CMakeFiles/mr_worker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sarah/Documents/AOS/project4/cs6210-mapreduce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/mr_worker"
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mr_worker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/mr_worker.dir/build: bin/mr_worker

.PHONY : test/CMakeFiles/mr_worker.dir/build

test/CMakeFiles/mr_worker.dir/clean:
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test && $(CMAKE_COMMAND) -P CMakeFiles/mr_worker.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/mr_worker.dir/clean

test/CMakeFiles/mr_worker.dir/depend:
	cd /home/sarah/Documents/AOS/project4/cs6210-mapreduce && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sarah/Documents/AOS/project4/cs6210-mapreduce /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test /home/sarah/Documents/AOS/project4/cs6210-mapreduce /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test /home/sarah/Documents/AOS/project4/cs6210-mapreduce/test/CMakeFiles/mr_worker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/mr_worker.dir/depend

