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
CMAKE_SOURCE_DIR = /home/gl/workspace/enet/udp_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gl/workspace/enet/udp_client

# Include any dependencies generated for this target.
include CMakeFiles/udp_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_client.dir/flags.make

CMakeFiles/udp_client.dir/host.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/host.c.o: host.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/host.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/host.c.o   -c /home/gl/workspace/enet/udp_client/host.c

CMakeFiles/udp_client.dir/host.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/host.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/host.c > CMakeFiles/udp_client.dir/host.c.i

CMakeFiles/udp_client.dir/host.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/host.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/host.c -o CMakeFiles/udp_client.dir/host.c.s

CMakeFiles/udp_client.dir/host.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/host.c.o.requires

CMakeFiles/udp_client.dir/host.c.o.provides: CMakeFiles/udp_client.dir/host.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/host.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/host.c.o.provides

CMakeFiles/udp_client.dir/host.c.o.provides.build: CMakeFiles/udp_client.dir/host.c.o

CMakeFiles/udp_client.dir/unix.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/unix.c.o: unix.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/unix.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/unix.c.o   -c /home/gl/workspace/enet/udp_client/unix.c

CMakeFiles/udp_client.dir/unix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/unix.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/unix.c > CMakeFiles/udp_client.dir/unix.c.i

CMakeFiles/udp_client.dir/unix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/unix.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/unix.c -o CMakeFiles/udp_client.dir/unix.c.s

CMakeFiles/udp_client.dir/unix.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/unix.c.o.requires

CMakeFiles/udp_client.dir/unix.c.o.provides: CMakeFiles/udp_client.dir/unix.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/unix.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/unix.c.o.provides

CMakeFiles/udp_client.dir/unix.c.o.provides.build: CMakeFiles/udp_client.dir/unix.c.o

CMakeFiles/udp_client.dir/list.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/list.c.o: list.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/list.c.o   -c /home/gl/workspace/enet/udp_client/list.c

CMakeFiles/udp_client.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/list.c > CMakeFiles/udp_client.dir/list.c.i

CMakeFiles/udp_client.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/list.c -o CMakeFiles/udp_client.dir/list.c.s

CMakeFiles/udp_client.dir/list.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/list.c.o.requires

CMakeFiles/udp_client.dir/list.c.o.provides: CMakeFiles/udp_client.dir/list.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/list.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/list.c.o.provides

CMakeFiles/udp_client.dir/list.c.o.provides.build: CMakeFiles/udp_client.dir/list.c.o

CMakeFiles/udp_client.dir/packet.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/packet.c.o: packet.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/packet.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/packet.c.o   -c /home/gl/workspace/enet/udp_client/packet.c

CMakeFiles/udp_client.dir/packet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/packet.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/packet.c > CMakeFiles/udp_client.dir/packet.c.i

CMakeFiles/udp_client.dir/packet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/packet.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/packet.c -o CMakeFiles/udp_client.dir/packet.c.s

CMakeFiles/udp_client.dir/packet.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/packet.c.o.requires

CMakeFiles/udp_client.dir/packet.c.o.provides: CMakeFiles/udp_client.dir/packet.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/packet.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/packet.c.o.provides

CMakeFiles/udp_client.dir/packet.c.o.provides.build: CMakeFiles/udp_client.dir/packet.c.o

CMakeFiles/udp_client.dir/win32.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/win32.c.o: win32.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/win32.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/win32.c.o   -c /home/gl/workspace/enet/udp_client/win32.c

CMakeFiles/udp_client.dir/win32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/win32.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/win32.c > CMakeFiles/udp_client.dir/win32.c.i

CMakeFiles/udp_client.dir/win32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/win32.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/win32.c -o CMakeFiles/udp_client.dir/win32.c.s

CMakeFiles/udp_client.dir/win32.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/win32.c.o.requires

CMakeFiles/udp_client.dir/win32.c.o.provides: CMakeFiles/udp_client.dir/win32.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/win32.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/win32.c.o.provides

CMakeFiles/udp_client.dir/win32.c.o.provides.build: CMakeFiles/udp_client.dir/win32.c.o

CMakeFiles/udp_client.dir/callbacks.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/callbacks.c.o: callbacks.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/callbacks.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/callbacks.c.o   -c /home/gl/workspace/enet/udp_client/callbacks.c

CMakeFiles/udp_client.dir/callbacks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/callbacks.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/callbacks.c > CMakeFiles/udp_client.dir/callbacks.c.i

CMakeFiles/udp_client.dir/callbacks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/callbacks.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/callbacks.c -o CMakeFiles/udp_client.dir/callbacks.c.s

CMakeFiles/udp_client.dir/callbacks.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/callbacks.c.o.requires

CMakeFiles/udp_client.dir/callbacks.c.o.provides: CMakeFiles/udp_client.dir/callbacks.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/callbacks.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/callbacks.c.o.provides

CMakeFiles/udp_client.dir/callbacks.c.o.provides.build: CMakeFiles/udp_client.dir/callbacks.c.o

CMakeFiles/udp_client.dir/peer.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/peer.c.o: peer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/peer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/peer.c.o   -c /home/gl/workspace/enet/udp_client/peer.c

CMakeFiles/udp_client.dir/peer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/peer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/peer.c > CMakeFiles/udp_client.dir/peer.c.i

CMakeFiles/udp_client.dir/peer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/peer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/peer.c -o CMakeFiles/udp_client.dir/peer.c.s

CMakeFiles/udp_client.dir/peer.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/peer.c.o.requires

CMakeFiles/udp_client.dir/peer.c.o.provides: CMakeFiles/udp_client.dir/peer.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/peer.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/peer.c.o.provides

CMakeFiles/udp_client.dir/peer.c.o.provides.build: CMakeFiles/udp_client.dir/peer.c.o

CMakeFiles/udp_client.dir/protocol.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/protocol.c.o: protocol.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/protocol.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/protocol.c.o   -c /home/gl/workspace/enet/udp_client/protocol.c

CMakeFiles/udp_client.dir/protocol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/protocol.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/protocol.c > CMakeFiles/udp_client.dir/protocol.c.i

CMakeFiles/udp_client.dir/protocol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/protocol.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/protocol.c -o CMakeFiles/udp_client.dir/protocol.c.s

CMakeFiles/udp_client.dir/protocol.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/protocol.c.o.requires

CMakeFiles/udp_client.dir/protocol.c.o.provides: CMakeFiles/udp_client.dir/protocol.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/protocol.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/protocol.c.o.provides

CMakeFiles/udp_client.dir/protocol.c.o.provides.build: CMakeFiles/udp_client.dir/protocol.c.o

CMakeFiles/udp_client.dir/compress.c.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/compress.c.o: compress.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/udp_client.dir/compress.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/udp_client.dir/compress.c.o   -c /home/gl/workspace/enet/udp_client/compress.c

CMakeFiles/udp_client.dir/compress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_client.dir/compress.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gl/workspace/enet/udp_client/compress.c > CMakeFiles/udp_client.dir/compress.c.i

CMakeFiles/udp_client.dir/compress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_client.dir/compress.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gl/workspace/enet/udp_client/compress.c -o CMakeFiles/udp_client.dir/compress.c.s

CMakeFiles/udp_client.dir/compress.c.o.requires:
.PHONY : CMakeFiles/udp_client.dir/compress.c.o.requires

CMakeFiles/udp_client.dir/compress.c.o.provides: CMakeFiles/udp_client.dir/compress.c.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/compress.c.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/compress.c.o.provides

CMakeFiles/udp_client.dir/compress.c.o.provides.build: CMakeFiles/udp_client.dir/compress.c.o

CMakeFiles/udp_client.dir/main.cpp.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/enet/udp_client/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/udp_client.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/udp_client.dir/main.cpp.o -c /home/gl/workspace/enet/udp_client/main.cpp

CMakeFiles/udp_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/enet/udp_client/main.cpp > CMakeFiles/udp_client.dir/main.cpp.i

CMakeFiles/udp_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/enet/udp_client/main.cpp -o CMakeFiles/udp_client.dir/main.cpp.s

CMakeFiles/udp_client.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/udp_client.dir/main.cpp.o.requires

CMakeFiles/udp_client.dir/main.cpp.o.provides: CMakeFiles/udp_client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/udp_client.dir/build.make CMakeFiles/udp_client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/udp_client.dir/main.cpp.o.provides

CMakeFiles/udp_client.dir/main.cpp.o.provides.build: CMakeFiles/udp_client.dir/main.cpp.o

# Object files for target udp_client
udp_client_OBJECTS = \
"CMakeFiles/udp_client.dir/host.c.o" \
"CMakeFiles/udp_client.dir/unix.c.o" \
"CMakeFiles/udp_client.dir/list.c.o" \
"CMakeFiles/udp_client.dir/packet.c.o" \
"CMakeFiles/udp_client.dir/win32.c.o" \
"CMakeFiles/udp_client.dir/callbacks.c.o" \
"CMakeFiles/udp_client.dir/peer.c.o" \
"CMakeFiles/udp_client.dir/protocol.c.o" \
"CMakeFiles/udp_client.dir/compress.c.o" \
"CMakeFiles/udp_client.dir/main.cpp.o"

# External object files for target udp_client
udp_client_EXTERNAL_OBJECTS =

udp_client: CMakeFiles/udp_client.dir/host.c.o
udp_client: CMakeFiles/udp_client.dir/unix.c.o
udp_client: CMakeFiles/udp_client.dir/list.c.o
udp_client: CMakeFiles/udp_client.dir/packet.c.o
udp_client: CMakeFiles/udp_client.dir/win32.c.o
udp_client: CMakeFiles/udp_client.dir/callbacks.c.o
udp_client: CMakeFiles/udp_client.dir/peer.c.o
udp_client: CMakeFiles/udp_client.dir/protocol.c.o
udp_client: CMakeFiles/udp_client.dir/compress.c.o
udp_client: CMakeFiles/udp_client.dir/main.cpp.o
udp_client: CMakeFiles/udp_client.dir/build.make
udp_client: CMakeFiles/udp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable udp_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_client.dir/build: udp_client
.PHONY : CMakeFiles/udp_client.dir/build

CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/host.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/unix.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/list.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/packet.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/win32.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/callbacks.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/peer.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/protocol.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/compress.c.o.requires
CMakeFiles/udp_client.dir/requires: CMakeFiles/udp_client.dir/main.cpp.o.requires
.PHONY : CMakeFiles/udp_client.dir/requires

CMakeFiles/udp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_client.dir/clean

CMakeFiles/udp_client.dir/depend:
	cd /home/gl/workspace/enet/udp_client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gl/workspace/enet/udp_client /home/gl/workspace/enet/udp_client /home/gl/workspace/enet/udp_client /home/gl/workspace/enet/udp_client /home/gl/workspace/enet/udp_client/CMakeFiles/udp_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_client.dir/depend

