# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lactosis/Documents/School/ACMSeminair

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lactosis/Documents/School/ACMSeminair/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Run.dir/flags.make

CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o: ../LS2020/mini3/necklace/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lactosis/Documents/School/ACMSeminair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o -c /home/lactosis/Documents/School/ACMSeminair/LS2020/mini3/necklace/main.cpp

CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lactosis/Documents/School/ACMSeminair/LS2020/mini3/necklace/main.cpp > CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.i

CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lactosis/Documents/School/ACMSeminair/LS2020/mini3/necklace/main.cpp -o CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.s

# Object files for target Run
Run_OBJECTS = \
"CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o"

# External object files for target Run
Run_EXTERNAL_OBJECTS =

Run: CMakeFiles/Run.dir/LS2020/mini3/necklace/main.cpp.o
Run: CMakeFiles/Run.dir/build.make
Run: CMakeFiles/Run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lactosis/Documents/School/ACMSeminair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Run.dir/build: Run

.PHONY : CMakeFiles/Run.dir/build

CMakeFiles/Run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Run.dir/clean

CMakeFiles/Run.dir/depend:
	cd /home/lactosis/Documents/School/ACMSeminair/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lactosis/Documents/School/ACMSeminair /home/lactosis/Documents/School/ACMSeminair /home/lactosis/Documents/School/ACMSeminair/cmake-build-debug /home/lactosis/Documents/School/ACMSeminair/cmake-build-debug /home/lactosis/Documents/School/ACMSeminair/cmake-build-debug/CMakeFiles/Run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Run.dir/depend

