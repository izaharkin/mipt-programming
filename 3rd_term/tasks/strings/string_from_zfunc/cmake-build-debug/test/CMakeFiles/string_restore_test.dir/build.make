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
CMAKE_SOURCE_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/string_restore_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/string_restore_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/string_restore_test.dir/flags.make

test/CMakeFiles/string_restore_test.dir/global_test.cpp.o: test/CMakeFiles/string_restore_test.dir/flags.make
test/CMakeFiles/string_restore_test.dir/global_test.cpp.o: ../test/global_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/string_restore_test.dir/global_test.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_restore_test.dir/global_test.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/test/global_test.cpp

test/CMakeFiles/string_restore_test.dir/global_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_restore_test.dir/global_test.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/test/global_test.cpp > CMakeFiles/string_restore_test.dir/global_test.cpp.i

test/CMakeFiles/string_restore_test.dir/global_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_restore_test.dir/global_test.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/test/global_test.cpp -o CMakeFiles/string_restore_test.dir/global_test.cpp.s

test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.requires:

.PHONY : test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.requires

test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.provides: test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/string_restore_test.dir/build.make test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.provides

test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.provides.build: test/CMakeFiles/string_restore_test.dir/global_test.cpp.o


# Object files for target string_restore_test
string_restore_test_OBJECTS = \
"CMakeFiles/string_restore_test.dir/global_test.cpp.o"

# External object files for target string_restore_test
string_restore_test_EXTERNAL_OBJECTS =

test/string_restore_test: test/CMakeFiles/string_restore_test.dir/global_test.cpp.o
test/string_restore_test: test/CMakeFiles/string_restore_test.dir/build.make
test/string_restore_test: src/libstring_restore_lib.so
test/string_restore_test: test/CMakeFiles/string_restore_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable string_restore_test"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_restore_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/string_restore_test.dir/build: test/string_restore_test

.PHONY : test/CMakeFiles/string_restore_test.dir/build

test/CMakeFiles/string_restore_test.dir/requires: test/CMakeFiles/string_restore_test.dir/global_test.cpp.o.requires

.PHONY : test/CMakeFiles/string_restore_test.dir/requires

test/CMakeFiles/string_restore_test.dir/clean:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/string_restore_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/string_restore_test.dir/clean

test/CMakeFiles/string_restore_test.dir/depend:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/test /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_zfunc/cmake-build-debug/test/CMakeFiles/string_restore_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/string_restore_test.dir/depend

