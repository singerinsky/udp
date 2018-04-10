cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 OLD)

#set the lib in this os 
#if your os is ubuntu set libname as ubuntu ;if os is centos set libname as centos ;if os is qq's suse set libname as qq
set(libname "ubuntu")

#set out put path
SET(EXECUTABLE_OUTPUT_PATH ./)

PROJECT (game_exe)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -O0 -Wall -g -pg -D_GNU_SOURCE -fPIC")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -O0 -Wall -g -pg -D_GNU_SOURCE -fPIC")

#set build targe
SET(CMAKE_BUILD_TYPE DEBUG)
#SET(CMAKE_BUILD_TYPE RELEASE)

MESSAGE("Building ${CMAKE_CXX_FLAGS_DEBUG}")

INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(./proto_message)
LINK_DIRECTORIES(./lib)

ADD_SUBDIRECTORY(proto_message proto_message)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(udp_server ${DIR_SRCS})
TARGET_LINK_LIBRARIES(udp_server pthread glog gflags protobuf message_lib)
