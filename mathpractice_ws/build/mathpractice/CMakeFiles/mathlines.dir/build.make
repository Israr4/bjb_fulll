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
CMAKE_SOURCE_DIR = /home/maanz-ai/mathpractice_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maanz-ai/mathpractice_ws/build

# Include any dependencies generated for this target.
include mathpractice/CMakeFiles/mathlines.dir/depend.make

# Include the progress variables for this target.
include mathpractice/CMakeFiles/mathlines.dir/progress.make

# Include the compile flags for this target's objects.
include mathpractice/CMakeFiles/mathlines.dir/flags.make

mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.o: mathpractice/CMakeFiles/mathlines.dir/flags.make
mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.o: /home/maanz-ai/mathpractice_ws/src/mathpractice/src/mathline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maanz-ai/mathpractice_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.o"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mathlines.dir/src/mathline.cpp.o -c /home/maanz-ai/mathpractice_ws/src/mathpractice/src/mathline.cpp

mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mathlines.dir/src/mathline.cpp.i"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maanz-ai/mathpractice_ws/src/mathpractice/src/mathline.cpp > CMakeFiles/mathlines.dir/src/mathline.cpp.i

mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mathlines.dir/src/mathline.cpp.s"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maanz-ai/mathpractice_ws/src/mathpractice/src/mathline.cpp -o CMakeFiles/mathlines.dir/src/mathline.cpp.s

mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.o: mathpractice/CMakeFiles/mathlines.dir/flags.make
mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.o: /home/maanz-ai/mathpractice_ws/src/mathpractice/src/rosline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maanz-ai/mathpractice_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.o"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mathlines.dir/src/rosline.cpp.o -c /home/maanz-ai/mathpractice_ws/src/mathpractice/src/rosline.cpp

mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mathlines.dir/src/rosline.cpp.i"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maanz-ai/mathpractice_ws/src/mathpractice/src/rosline.cpp > CMakeFiles/mathlines.dir/src/rosline.cpp.i

mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mathlines.dir/src/rosline.cpp.s"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maanz-ai/mathpractice_ws/src/mathpractice/src/rosline.cpp -o CMakeFiles/mathlines.dir/src/rosline.cpp.s

# Object files for target mathlines
mathlines_OBJECTS = \
"CMakeFiles/mathlines.dir/src/mathline.cpp.o" \
"CMakeFiles/mathlines.dir/src/rosline.cpp.o"

# External object files for target mathlines
mathlines_EXTERNAL_OBJECTS =

/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: mathpractice/CMakeFiles/mathlines.dir/src/mathline.cpp.o
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: mathpractice/CMakeFiles/mathlines.dir/src/rosline.cpp.o
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: mathpractice/CMakeFiles/mathlines.dir/build.make
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/libroscpp.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/librosconsole.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/librostime.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /opt/ros/noetic/lib/libcpp_common.so
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines: mathpractice/CMakeFiles/mathlines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maanz-ai/mathpractice_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines"
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mathlines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mathpractice/CMakeFiles/mathlines.dir/build: /home/maanz-ai/mathpractice_ws/devel/lib/mathpractice/mathlines

.PHONY : mathpractice/CMakeFiles/mathlines.dir/build

mathpractice/CMakeFiles/mathlines.dir/clean:
	cd /home/maanz-ai/mathpractice_ws/build/mathpractice && $(CMAKE_COMMAND) -P CMakeFiles/mathlines.dir/cmake_clean.cmake
.PHONY : mathpractice/CMakeFiles/mathlines.dir/clean

mathpractice/CMakeFiles/mathlines.dir/depend:
	cd /home/maanz-ai/mathpractice_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maanz-ai/mathpractice_ws/src /home/maanz-ai/mathpractice_ws/src/mathpractice /home/maanz-ai/mathpractice_ws/build /home/maanz-ai/mathpractice_ws/build/mathpractice /home/maanz-ai/mathpractice_ws/build/mathpractice/CMakeFiles/mathlines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mathpractice/CMakeFiles/mathlines.dir/depend

