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
CMAKE_SOURCE_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B1_From_Prefix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B1_From_Prefix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B1_From_Prefix.dir/flags.make

CMakeFiles/B1_From_Prefix.dir/main.cpp.o: CMakeFiles/B1_From_Prefix.dir/flags.make
CMakeFiles/B1_From_Prefix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B1_From_Prefix.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/B1_From_Prefix.dir/main.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/main.cpp

CMakeFiles/B1_From_Prefix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B1_From_Prefix.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/main.cpp > CMakeFiles/B1_From_Prefix.dir/main.cpp.i

CMakeFiles/B1_From_Prefix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B1_From_Prefix.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/main.cpp -o CMakeFiles/B1_From_Prefix.dir/main.cpp.s

CMakeFiles/B1_From_Prefix.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/B1_From_Prefix.dir/main.cpp.o.requires

CMakeFiles/B1_From_Prefix.dir/main.cpp.o.provides: CMakeFiles/B1_From_Prefix.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/B1_From_Prefix.dir/build.make CMakeFiles/B1_From_Prefix.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/B1_From_Prefix.dir/main.cpp.o.provides

CMakeFiles/B1_From_Prefix.dir/main.cpp.o.provides.build: CMakeFiles/B1_From_Prefix.dir/main.cpp.o


# Object files for target B1_From_Prefix
B1_From_Prefix_OBJECTS = \
"CMakeFiles/B1_From_Prefix.dir/main.cpp.o"

# External object files for target B1_From_Prefix
B1_From_Prefix_EXTERNAL_OBJECTS =

B1_From_Prefix: CMakeFiles/B1_From_Prefix.dir/main.cpp.o
B1_From_Prefix: CMakeFiles/B1_From_Prefix.dir/build.make
B1_From_Prefix: src/libstring_restoring_lib.so
B1_From_Prefix: CMakeFiles/B1_From_Prefix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B1_From_Prefix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/B1_From_Prefix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B1_From_Prefix.dir/build: B1_From_Prefix

.PHONY : CMakeFiles/B1_From_Prefix.dir/build

CMakeFiles/B1_From_Prefix.dir/requires: CMakeFiles/B1_From_Prefix.dir/main.cpp.o.requires

.PHONY : CMakeFiles/B1_From_Prefix.dir/requires

CMakeFiles/B1_From_Prefix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/B1_From_Prefix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/B1_From_Prefix.dir/clean

CMakeFiles/B1_From_Prefix.dir/depend:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/string_from_prefix/cmake-build-debug/CMakeFiles/B1_From_Prefix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B1_From_Prefix.dir/depend
