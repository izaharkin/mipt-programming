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
CMAKE_SOURCE_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/ford_bellman_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ford_bellman_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ford_bellman_lib.dir/flags.make

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o: src/CMakeFiles/ford_bellman_lib.dir/flags.make
src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o: ../src/Edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Edge.cpp

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ford_bellman_lib.dir/Edge.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Edge.cpp > CMakeFiles/ford_bellman_lib.dir/Edge.cpp.i

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ford_bellman_lib.dir/Edge.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Edge.cpp -o CMakeFiles/ford_bellman_lib.dir/Edge.cpp.s

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.requires:

.PHONY : src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.requires

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.provides: src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ford_bellman_lib.dir/build.make src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.provides.build
.PHONY : src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.provides

src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.provides.build: src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o


src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o: src/CMakeFiles/ford_bellman_lib.dir/flags.make
src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o: ../src/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Graph.cpp

src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ford_bellman_lib.dir/Graph.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Graph.cpp > CMakeFiles/ford_bellman_lib.dir/Graph.cpp.i

src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ford_bellman_lib.dir/Graph.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/Graph.cpp -o CMakeFiles/ford_bellman_lib.dir/Graph.cpp.s

src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.requires:

.PHONY : src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.requires

src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.provides: src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ford_bellman_lib.dir/build.make src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.provides.build
.PHONY : src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.provides

src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.provides.build: src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o


src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o: src/CMakeFiles/ford_bellman_lib.dir/flags.make
src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o: ../src/TradeArbitrageSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o -c /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/TradeArbitrageSolver.cpp

src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.i"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/TradeArbitrageSolver.cpp > CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.i

src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.s"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src/TradeArbitrageSolver.cpp -o CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.s

src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.requires:

.PHONY : src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.requires

src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.provides: src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ford_bellman_lib.dir/build.make src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.provides.build
.PHONY : src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.provides

src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.provides.build: src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o


# Object files for target ford_bellman_lib
ford_bellman_lib_OBJECTS = \
"CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o" \
"CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o" \
"CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o"

# External object files for target ford_bellman_lib
ford_bellman_lib_EXTERNAL_OBJECTS =

src/libford_bellman_lib.a: src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o
src/libford_bellman_lib.a: src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o
src/libford_bellman_lib.a: src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o
src/libford_bellman_lib.a: src/CMakeFiles/ford_bellman_lib.dir/build.make
src/libford_bellman_lib.a: src/CMakeFiles/ford_bellman_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libford_bellman_lib.a"
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/ford_bellman_lib.dir/cmake_clean_target.cmake
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ford_bellman_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ford_bellman_lib.dir/build: src/libford_bellman_lib.a

.PHONY : src/CMakeFiles/ford_bellman_lib.dir/build

src/CMakeFiles/ford_bellman_lib.dir/requires: src/CMakeFiles/ford_bellman_lib.dir/Edge.cpp.o.requires
src/CMakeFiles/ford_bellman_lib.dir/requires: src/CMakeFiles/ford_bellman_lib.dir/Graph.cpp.o.requires
src/CMakeFiles/ford_bellman_lib.dir/requires: src/CMakeFiles/ford_bellman_lib.dir/TradeArbitrageSolver.cpp.o.requires

.PHONY : src/CMakeFiles/ford_bellman_lib.dir/requires

src/CMakeFiles/ford_bellman_lib.dir/clean:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/ford_bellman_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ford_bellman_lib.dir/clean

src/CMakeFiles/ford_bellman_lib.dir/depend:
	cd /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/src /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src /home/ilya/Yandex.Disk/PROGRAMMING/MIPT/3rd_term/tasks/trade_arbitrage/cmake-build-debug/src/CMakeFiles/ford_bellman_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ford_bellman_lib.dir/depend

