##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## Run the unit tests via Catch framework.
##
## For testing on function/class level.
##

add_executable(unit_testsuite EXCLUDE_FROM_ALL
    ../src/main.cpp test_main.cpp
    ${CMAKE_BINARY_DIR}/src/version.cpp test_version.cpp)

# ensure all dependecies
add_dependencies(unit_testsuite Catch)   # Catch is needed for unit tests
target_compile_definitions(unit_testsuite PRIVATE UNIT_TESTS)    # add -DUNIT_TESTS if the tests are running
target_include_directories(unit_testsuite PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_include_directories(unit_testsuite SYSTEM PRIVATE ${CATCH_INCLUDE_DIR})


# convenience target for running only the unit tests
add_custom_target(unit
        #this way we can use faux data from /tests dir (if we have any):
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
        COMMAND $<TARGET_FILE:unit_testsuite>
        COMMENT "Running unit tests"
        DEPENDS unit_testsuite)

# Verbose printing of results
add_custom_target(unitall
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
        COMMAND $<TARGET_FILE:unit_testsuite> -s -a -r=compact
        COMMENT "Running unit tests - verbose mode"
        DEPENDS unit_testsuite)




#include(CTest)

# Convenience targets for fast testing, they depends on binaries (so the build
# is triggered, when sources were changed).
add_custom_target(check
        COMMAND echo [----] Running tests
        USES_TERMINAL
        COMMAND ${CMAKE_CTEST_COMMAND}  --output-on-failure -C Debug
        DEPENDS ${PROJECT_NAME} unit_testsuite)

add_custom_target(checkVerbose
        COMMAND echo [----] Running tests
        USES_TERMINAL
        COMMAND ${CMAKE_CTEST_COMMAND}  -V --output-on-failure -C Debug
        DEPENDS ${PROJECT_NAME} unit_testsuite)

#------------------------------------------------------------------------------
# CTest test suite
#
# Test suite is defined here, when executed test fails (returns not 0), test
# failed. There are more options, check CMake documentation.
#
# Good to use to integration test, run whole program with parameters,
# check if it will crash, produce correct results, etc.
#include(CTest)

# Basic runable tests (will not crash)
add_test(NAME "Is_Runable "
        COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

add_test(NAME "Is_Runable-v"
        COMMAND $<TARGET_FILE:${PROJECT_NAME}> -v)

add_test(NAME "Is_Runable-h"
        COMMAND $<TARGET_FILE:${PROJECT_NAME}> -h)





# Add unit test to CTest suite as one of the tests
# unit test build is located in source/unittest/CMakeLists.txt
add_test(NAME "catch_unit_tests"
        COMMAND $<TARGET_FILE:unit_testsuite>
        #USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

