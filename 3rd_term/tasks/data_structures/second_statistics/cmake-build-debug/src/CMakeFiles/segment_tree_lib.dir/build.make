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
CMAKE_SOURCE_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/segment_tree_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/segment_tree_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/segment_tree_lib.dir/flags.make

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o: src/CMakeFiles/segment_tree_lib.dir/flags.make
src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o: ../src/SegmentTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SegmentTree.cpp

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SegmentTree.cpp > CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.i

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SegmentTree.cpp -o CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.s

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.requires:

.PHONY : src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.requires

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.provides: src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/segment_tree_lib.dir/build.make src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.provides.build
.PHONY : src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.provides

src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.provides.build: src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o


src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o: src/CMakeFiles/segment_tree_lib.dir/flags.make
src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o: ../src/SecondStatisticsSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SecondStatisticsSolver.cpp

src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SecondStatisticsSolver.cpp > CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.i

src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src/SecondStatisticsSolver.cpp -o CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.s

src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.requires:

.PHONY : src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.requires

src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.provides: src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/segment_tree_lib.dir/build.make src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.provides.build
.PHONY : src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.provides

src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.provides.build: src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o


# Object files for target segment_tree_lib
segment_tree_lib_OBJECTS = \
"CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o" \
"CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o"

# External object files for target segment_tree_lib
segment_tree_lib_EXTERNAL_OBJECTS =

src/libsegment_tree_lib.a: src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o
src/libsegment_tree_lib.a: src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o
src/libsegment_tree_lib.a: src/CMakeFiles/segment_tree_lib.dir/build.make
src/libsegment_tree_lib.a: src/CMakeFiles/segment_tree_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libsegment_tree_lib.a"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/segment_tree_lib.dir/cmake_clean_target.cmake
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/segment_tree_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/segment_tree_lib.dir/build: src/libsegment_tree_lib.a

.PHONY : src/CMakeFiles/segment_tree_lib.dir/build

src/CMakeFiles/segment_tree_lib.dir/requires: src/CMakeFiles/segment_tree_lib.dir/SegmentTree.cpp.o.requires
src/CMakeFiles/segment_tree_lib.dir/requires: src/CMakeFiles/segment_tree_lib.dir/SecondStatisticsSolver.cpp.o.requires

.PHONY : src/CMakeFiles/segment_tree_lib.dir/requires

src/CMakeFiles/segment_tree_lib.dir/clean:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/segment_tree_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/segment_tree_lib.dir/clean

src/CMakeFiles/segment_tree_lib.dir/depend:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/src /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/second_statistics/cmake-build-debug/src/CMakeFiles/segment_tree_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/segment_tree_lib.dir/depend

