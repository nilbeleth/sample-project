##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## Run the unit tests if requested.
##

enable_testing()

add_executable(unittests EXCLUDE_FROM_ALL
    test_main.cpp
    ../src/main.cpp
    )

add_dependencies(unittests Catch)   # Cathc is needed for unit tests
target_compile_definitions(unittests PRIVATE UNIT_TESTS)    # add -DUNIT_TESTS define_property
target_include_directories(unittests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_include_directories(unittests SYSTEM PRIVATE ${CATCH_INCLUDE_DIR})

add_custom_command(unit
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
    COMMAND $<TARGET_FILE:unittests>
    DEPENDS unittests)

add_custom_command(unitall
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
    COMMAND $<TARGET_FILE:unittests> -s -a -r=compact
    DEPENDS unittests)

message(AUTHOR_WARNING "DEBUG: ${CATCH_INCLUDE_DIR}")
