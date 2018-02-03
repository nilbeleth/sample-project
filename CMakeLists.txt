# stop if cmake version is below 2.8
cmake_minimum_required (VERSION 2.8)


# project name
project (sample-project)


# enable only C/C++
#enable_language(C CXX)


# project version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find config.h
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")


# add the executable
add_executable(sample-project main.cpp)
