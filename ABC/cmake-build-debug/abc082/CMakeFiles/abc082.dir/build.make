# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/s02825/CLionProjects/atCoder/ABC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug

# Include any dependencies generated for this target.
include abc082/CMakeFiles/abc082.dir/depend.make

# Include the progress variables for this target.
include abc082/CMakeFiles/abc082.dir/progress.make

# Include the compile flags for this target's objects.
include abc082/CMakeFiles/abc082.dir/flags.make

abc082/CMakeFiles/abc082.dir/A.cpp.o: abc082/CMakeFiles/abc082.dir/flags.make
abc082/CMakeFiles/abc082.dir/A.cpp.o: ../abc082/A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object abc082/CMakeFiles/abc082.dir/A.cpp.o"
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abc082.dir/A.cpp.o -c /Users/s02825/CLionProjects/atCoder/ABC/abc082/A.cpp

abc082/CMakeFiles/abc082.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abc082.dir/A.cpp.i"
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/s02825/CLionProjects/atCoder/ABC/abc082/A.cpp > CMakeFiles/abc082.dir/A.cpp.i

abc082/CMakeFiles/abc082.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abc082.dir/A.cpp.s"
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/s02825/CLionProjects/atCoder/ABC/abc082/A.cpp -o CMakeFiles/abc082.dir/A.cpp.s

# Object files for target abc082
abc082_OBJECTS = \
"CMakeFiles/abc082.dir/A.cpp.o"

# External object files for target abc082
abc082_EXTERNAL_OBJECTS =

abc082/abc082: abc082/CMakeFiles/abc082.dir/A.cpp.o
abc082/abc082: abc082/CMakeFiles/abc082.dir/build.make
abc082/abc082: abc082/CMakeFiles/abc082.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable abc082"
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abc082.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
abc082/CMakeFiles/abc082.dir/build: abc082/abc082

.PHONY : abc082/CMakeFiles/abc082.dir/build

abc082/CMakeFiles/abc082.dir/clean:
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 && $(CMAKE_COMMAND) -P CMakeFiles/abc082.dir/cmake_clean.cmake
.PHONY : abc082/CMakeFiles/abc082.dir/clean

abc082/CMakeFiles/abc082.dir/depend:
	cd /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/s02825/CLionProjects/atCoder/ABC /Users/s02825/CLionProjects/atCoder/ABC/abc082 /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082 /Users/s02825/CLionProjects/atCoder/ABC/cmake-build-debug/abc082/CMakeFiles/abc082.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : abc082/CMakeFiles/abc082.dir/depend

