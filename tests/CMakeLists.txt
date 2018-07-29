##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## This CMkae file should take care of all test environments.
##


##-----------------------------------------------------------------------------
## Unit test suite
##
## Testing via Catch framework (testing on function/class level)
##

set(UTEST_EXE utest_${PROJECT_NAME} CACHE INTERNAL "A name for unit test executable")

# create the unit test executable
add_executable(${UTEST_EXE} EXCLUDE_FROM_ALL
    test_main.cpp
    ${CMAKE_BINARY_DIR}/src/version.cpp test_version.cpp)

# ensure all dependecies
add_dependencies(${UTEST_EXE} Catch)   # Catch is needed for unit tests
target_compile_definitions(${UTEST_EXE} PRIVATE UNIT_TESTS)    # add -DUNIT_TESTS if the tests are running
target_include_directories(${UTEST_EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_include_directories(${UTEST_EXE} SYSTEM PRIVATE ${CATCH_INCLUDE_DIR})


# convenience target for running only the unit tests
add_custom_target(unit
        #this way we can use faux data from /tests dir (if we have any):
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
        COMMAND $<TARGET_FILE:${UTEST_EXE}>
        COMMENT "Running unit tests"
        DEPENDS ${UTEST_EXE})

# Verbose printing of results
add_custom_target(unitVerbose
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
        COMMAND $<TARGET_FILE:${UTEST_EXE}> -s -a -r=compact
        COMMENT "Running unit tests - verbose mode"
        DEPENDS ${UTEST_EXE})


##-----------------------------------------------------------------------------
## Integration test suite
##
## Testing via CTest framework
##

# Basic runable tests (should not crash)
add_test(NAME "Is_Runable "
        COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

add_test(NAME "Is_Runable-v"
        COMMAND $<TARGET_FILE:${PROJECT_NAME}> -v)

add_test(NAME "Is_Runable-h"
        COMMAND $<TARGET_FILE:${PROJECT_NAME}> -h)


# Add unit test to CTest suite as one of the tests
add_test(NAME "catch_unit_tests"
        COMMAND $<TARGET_FILE:${UTEST_EXE}>
        #USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


##-----------------------------------------------------------------------------
## Putting it all together
##

# Convenience targets for fast testing, they depends on binaries (so the build
# is triggered, when sources were changed).
add_custom_target(check
        COMMAND echo [----] Running tests
        USES_TERMINAL
        COMMAND ${CMAKE_CTEST_COMMAND}  --output-on-failure -C Debug
        DEPENDS ${PROJECT_NAME} ${UTEST_EXE})

add_custom_target(checkVerbose
        COMMAND echo [----] Running tests
        USES_TERMINAL
        COMMAND ${CMAKE_CTEST_COMMAND}  -V --output-on-failure -C Debug
        DEPENDS ${PROJECT_NAME} ${UTEST_EXE})
