# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/gl/git/udp/udp_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gl/git/udp/udp_server

# Include any dependencies generated for this target.
include common/CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include common/CMakeFiles/common.dir/flags.make

common/CMakeFiles/common.dir/thread.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/thread.cpp.o: common/thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/git/udp/udp_server/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/thread.cpp.o"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/thread.cpp.o -c /home/gl/git/udp/udp_server/common/thread.cpp

common/CMakeFiles/common.dir/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/thread.cpp.i"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/git/udp/udp_server/common/thread.cpp > CMakeFiles/common.dir/thread.cpp.i

common/CMakeFiles/common.dir/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/thread.cpp.s"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/git/udp/udp_server/common/thread.cpp -o CMakeFiles/common.dir/thread.cpp.s

common/CMakeFiles/common.dir/thread.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/thread.cpp.o.requires

common/CMakeFiles/common.dir/thread.cpp.o.provides: common/CMakeFiles/common.dir/thread.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/thread.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/thread.cpp.o.provides

common/CMakeFiles/common.dir/thread.cpp.o.provides.build: common/CMakeFiles/common.dir/thread.cpp.o

common/CMakeFiles/common.dir/timer_manager.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/timer_manager.cpp.o: common/timer_manager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/git/udp/udp_server/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/timer_manager.cpp.o"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/timer_manager.cpp.o -c /home/gl/git/udp/udp_server/common/timer_manager.cpp

common/CMakeFiles/common.dir/timer_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/timer_manager.cpp.i"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/git/udp/udp_server/common/timer_manager.cpp > CMakeFiles/common.dir/timer_manager.cpp.i

common/CMakeFiles/common.dir/timer_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/timer_manager.cpp.s"
	cd /home/gl/git/udp/udp_server/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/git/udp/udp_server/common/timer_manager.cpp -o CMakeFiles/common.dir/timer_manager.cpp.s

common/CMakeFiles/common.dir/timer_manager.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/timer_manager.cpp.o.requires

common/CMakeFiles/common.dir/timer_manager.cpp.o.provides: common/CMakeFiles/common.dir/timer_manager.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/timer_manager.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/timer_manager.cpp.o.provides

common/CMakeFiles/common.dir/timer_manager.cpp.o.provides.build: common/CMakeFiles/common.dir/timer_manager.cpp.o

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/thread.cpp.o" \
"CMakeFiles/common.dir/timer_manager.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

lib/libcommon.a: common/CMakeFiles/common.dir/thread.cpp.o
lib/libcommon.a: common/CMakeFiles/common.dir/timer_manager.cpp.o
lib/libcommon.a: common/CMakeFiles/common.dir/build.make
lib/libcommon.a: common/CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/libcommon.a"
	cd /home/gl/git/udp/udp_server/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean_target.cmake
	cd /home/gl/git/udp/udp_server/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/CMakeFiles/common.dir/build: lib/libcommon.a
.PHONY : common/CMakeFiles/common.dir/build

common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/thread.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/timer_manager.cpp.o.requires
.PHONY : common/CMakeFiles/common.dir/requires

common/CMakeFiles/common.dir/clean:
	cd /home/gl/git/udp/udp_server/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : common/CMakeFiles/common.dir/clean

common/CMakeFiles/common.dir/depend:
	cd /home/gl/git/udp/udp_server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gl/git/udp/udp_server /home/gl/git/udp/udp_server/common /home/gl/git/udp/udp_server /home/gl/git/udp/udp_server/common /home/gl/git/udp/udp_server/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/CMakeFiles/common.dir/depend

