##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## The project's main CMake configuration file.
##

cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

project (sample-project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# project version
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION_TWEAK 0)

set(VERSION_TYPE "alfa" CACHE STRING "version type" FORCE)
site_name(VERSION_HOST)
set(VERSION_HOST "${VERSION_HOST}" CACHE STRING "host of build" FORCE)

message(STATUS "")
message(STATUS "    == ${PROJECT_NAME} Project Configuration ==")
message(STATUS "")

# Export compile commands to json (it may by usefull for some tools like clang-tidy)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # this is actually not working in cmake 2.8


##-----------------------------------------------------------------------------
## Host information
##

# detect operating system
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_definitions(-DSYSTEM_LINUX)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")  # Mac OS X
    add_definitions(-DSYSTEM_DARWIN)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "AIX")
    add_definitions(-DSYSTEM_AIX)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_definitions(-DSYSTEM_WINDOWS)
endif()

# detect the host processor
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")


##-----------------------------------------------------------------------------
## Add additional cmake modules if necessary
##
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    )

# solve build type
include(BuildType)
# guard against in-source builds and bad build-type strings
#include(safeguards)


##-----------------------------------------------------------------------------
## Options for supplemental tools
##

#option(WITH_COVERAGE "Build with code coverage support (requires lcov and build with tests)." OFF)
#option(WITH_DOC "Build API documentation (requires Doxygen)." OFF)
#option(WITH_TESTS "Build tests (requires Google Test)." OFF)
#
#if(${WITH_COVERAGE})
#	set(WITH_TESTS ON)
#endif()


##-----------------------------------------------------------------------------
## Paths.
##

#if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "default install path" FORCE)
#endif()
#set(INSTALL_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin")
#set(INSTALL_DOC_DIR "${CMAKE_INSTALL_PREFIX}/doc")
#set(INSTALL_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include")
#set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")

##-----------------------------------------------------------------------------
## Includes.
##

#include_directories(include)


##-----------------------------------------------------------------------------
## Compiler options.
##

# C++11 is required.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic")

# Abort compilation upon the first error.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors")

# Standard warning parameters.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Enable additional warnings that are not included in -Wall and -Wextra
# (according to `man gcc`).
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)   # TODO (nilbeleth#1#): check if this goes also for clang of any other
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-align")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-qual")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuninitialized")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuseless-cast")
endif()

set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
#set(CMAKE_CXX_FLAGS -fprofile-arcs -ftest-coverage)

# Custom install target, used in run target in src/CMakeLists.txt
if(CMAKE_GENERATOR MATCHES "Makefiles")
    add_custom_target(Install_
                COMMAND "${CMAKE_COMMAND}" --build . --target install -- -j
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
else()
    add_custom_command(Install_
                COMMAND "${CMAKE_COMMAND}" --build . --target install
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()



##-----------------------------------------------------------------------------
## Include all subdirectories with potentional CMakeLists.txt
##

# External (3rd party) tools are downloaded here
add_subdirectory(external)

# Documentation
add_subdirectory(doc)

# Source code
add_subdirectory(src)

# Testing
enable_testing()
add_subdirectory(tests)


##-----------------------------------------------------------------------------
##
##
message(STATUS "")
message(STATUS "    == Final overview for ${PROJECT_NAME} ==")
message(STATUS "Version:            ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} - ${VERSION_TYPE}")
message(STATUS "Version host:       ${VERSION_HOST}")
message(STATUS "Install prefix:     ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_BUILD_TYPE:   ${CMAKE_BUILD_TYPE}")
message(STATUS "")

# add the binary tree to the search path for include files
# so that we will find config.h
#include_directories("${PROJECT_SOURCE_DIR}")
#include_directories("${PROJECT_BINARY_DIR}")



