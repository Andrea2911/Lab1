# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/awalker/CLionProjects/Lab1git/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1.dir/flags.make

CMakeFiles/Lab1.dir/aew0056_1.cpp.o: CMakeFiles/Lab1.dir/flags.make
CMakeFiles/Lab1.dir/aew0056_1.cpp.o: ../aew0056_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1.dir/aew0056_1.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1.dir/aew0056_1.cpp.o -c /home/awalker/CLionProjects/Lab1git/Lab1/aew0056_1.cpp

CMakeFiles/Lab1.dir/aew0056_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1.dir/aew0056_1.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awalker/CLionProjects/Lab1git/Lab1/aew0056_1.cpp > CMakeFiles/Lab1.dir/aew0056_1.cpp.i

CMakeFiles/Lab1.dir/aew0056_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1.dir/aew0056_1.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awalker/CLionProjects/Lab1git/Lab1/aew0056_1.cpp -o CMakeFiles/Lab1.dir/aew0056_1.cpp.s

CMakeFiles/Lab1.dir/aew0056_1.cpp.o.requires:

.PHONY : CMakeFiles/Lab1.dir/aew0056_1.cpp.o.requires

CMakeFiles/Lab1.dir/aew0056_1.cpp.o.provides: CMakeFiles/Lab1.dir/aew0056_1.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab1.dir/build.make CMakeFiles/Lab1.dir/aew0056_1.cpp.o.provides.build
.PHONY : CMakeFiles/Lab1.dir/aew0056_1.cpp.o.provides

CMakeFiles/Lab1.dir/aew0056_1.cpp.o.provides.build: CMakeFiles/Lab1.dir/aew0056_1.cpp.o


CMakeFiles/Lab1.dir/User.cpp.o: CMakeFiles/Lab1.dir/flags.make
CMakeFiles/Lab1.dir/User.cpp.o: ../User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab1.dir/User.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1.dir/User.cpp.o -c /home/awalker/CLionProjects/Lab1git/Lab1/User.cpp

CMakeFiles/Lab1.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1.dir/User.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awalker/CLionProjects/Lab1git/Lab1/User.cpp > CMakeFiles/Lab1.dir/User.cpp.i

CMakeFiles/Lab1.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1.dir/User.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awalker/CLionProjects/Lab1git/Lab1/User.cpp -o CMakeFiles/Lab1.dir/User.cpp.s

CMakeFiles/Lab1.dir/User.cpp.o.requires:

.PHONY : CMakeFiles/Lab1.dir/User.cpp.o.requires

CMakeFiles/Lab1.dir/User.cpp.o.provides: CMakeFiles/Lab1.dir/User.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab1.dir/build.make CMakeFiles/Lab1.dir/User.cpp.o.provides.build
.PHONY : CMakeFiles/Lab1.dir/User.cpp.o.provides

CMakeFiles/Lab1.dir/User.cpp.o.provides.build: CMakeFiles/Lab1.dir/User.cpp.o


# Object files for target Lab1
Lab1_OBJECTS = \
"CMakeFiles/Lab1.dir/aew0056_1.cpp.o" \
"CMakeFiles/Lab1.dir/User.cpp.o"

# External object files for target Lab1
Lab1_EXTERNAL_OBJECTS =

Lab1: CMakeFiles/Lab1.dir/aew0056_1.cpp.o
Lab1: CMakeFiles/Lab1.dir/User.cpp.o
Lab1: CMakeFiles/Lab1.dir/build.make
Lab1: CMakeFiles/Lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1.dir/build: Lab1

.PHONY : CMakeFiles/Lab1.dir/build

CMakeFiles/Lab1.dir/requires: CMakeFiles/Lab1.dir/aew0056_1.cpp.o.requires
CMakeFiles/Lab1.dir/requires: CMakeFiles/Lab1.dir/User.cpp.o.requires

.PHONY : CMakeFiles/Lab1.dir/requires

CMakeFiles/Lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab1.dir/clean

CMakeFiles/Lab1.dir/depend:
	cd /home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/awalker/CLionProjects/Lab1git/Lab1 /home/awalker/CLionProjects/Lab1git/Lab1 /home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug /home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug /home/awalker/CLionProjects/Lab1git/Lab1/cmake-build-debug/CMakeFiles/Lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1.dir/depend

