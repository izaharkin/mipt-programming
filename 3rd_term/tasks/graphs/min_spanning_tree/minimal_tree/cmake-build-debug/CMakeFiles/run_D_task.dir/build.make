# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/ilya/IDE/clion-2016.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ilya/IDE/clion-2016.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/run_D_task.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run_D_task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_D_task.dir/flags.make

CMakeFiles/run_D_task.dir/main.cpp.o: CMakeFiles/run_D_task.dir/flags.make
CMakeFiles/run_D_task.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_D_task.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_D_task.dir/main.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/main.cpp

CMakeFiles/run_D_task.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_D_task.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/main.cpp > CMakeFiles/run_D_task.dir/main.cpp.i

CMakeFiles/run_D_task.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_D_task.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/main.cpp -o CMakeFiles/run_D_task.dir/main.cpp.s

CMakeFiles/run_D_task.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/run_D_task.dir/main.cpp.o.requires

CMakeFiles/run_D_task.dir/main.cpp.o.provides: CMakeFiles/run_D_task.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/run_D_task.dir/build.make CMakeFiles/run_D_task.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/run_D_task.dir/main.cpp.o.provides

CMakeFiles/run_D_task.dir/main.cpp.o.provides.build: CMakeFiles/run_D_task.dir/main.cpp.o


CMakeFiles/run_D_task.dir/test/basic_check.cpp.o: CMakeFiles/run_D_task.dir/flags.make
CMakeFiles/run_D_task.dir/test/basic_check.cpp.o: ../test/basic_check.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_D_task.dir/test/basic_check.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_D_task.dir/test/basic_check.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/test/basic_check.cpp

CMakeFiles/run_D_task.dir/test/basic_check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_D_task.dir/test/basic_check.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/test/basic_check.cpp > CMakeFiles/run_D_task.dir/test/basic_check.cpp.i

CMakeFiles/run_D_task.dir/test/basic_check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_D_task.dir/test/basic_check.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/test/basic_check.cpp -o CMakeFiles/run_D_task.dir/test/basic_check.cpp.s

CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.requires:

.PHONY : CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.requires

CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.provides: CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.requires
	$(MAKE) -f CMakeFiles/run_D_task.dir/build.make CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.provides.build
.PHONY : CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.provides

CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.provides.build: CMakeFiles/run_D_task.dir/test/basic_check.cpp.o


# Object files for target run_D_task
run_D_task_OBJECTS = \
"CMakeFiles/run_D_task.dir/main.cpp.o" \
"CMakeFiles/run_D_task.dir/test/basic_check.cpp.o"

# External object files for target run_D_task
run_D_task_EXTERNAL_OBJECTS =

run_D_task: CMakeFiles/run_D_task.dir/main.cpp.o
run_D_task: CMakeFiles/run_D_task.dir/test/basic_check.cpp.o
run_D_task: CMakeFiles/run_D_task.dir/build.make
run_D_task: src/libmin_sp_tree_lib.a
run_D_task: CMakeFiles/run_D_task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_D_task"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_D_task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_D_task.dir/build: run_D_task

.PHONY : CMakeFiles/run_D_task.dir/build

CMakeFiles/run_D_task.dir/requires: CMakeFiles/run_D_task.dir/main.cpp.o.requires
CMakeFiles/run_D_task.dir/requires: CMakeFiles/run_D_task.dir/test/basic_check.cpp.o.requires

.PHONY : CMakeFiles/run_D_task.dir/requires

CMakeFiles/run_D_task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_D_task.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_D_task.dir/clean

CMakeFiles/run_D_task.dir/depend:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/minimal_tree/cmake-build-debug/CMakeFiles/run_D_task.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_D_task.dir/depend
