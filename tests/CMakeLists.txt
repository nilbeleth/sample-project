##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## Run the unit tests if requested.
##

enable_testing()

add_executable(unit_testsuite EXCLUDE_FROM_ALL
    ../src/main.cpp test_main.cpp
    ${CMAKE_BINARY_DIR}/src/version.cpp test_version.cpp)

add_dependencies(unit_testsuite Catch)   # Catch is needed for unit tests
target_compile_definitions(unit_testsuite PRIVATE UNIT_TESTS)    # add -DUNIT_TESTS if the tests are running
target_include_directories(unit_testsuite PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_include_directories(unit_testsuite SYSTEM PRIVATE ${CATCH_INCLUDE_DIR})


add_test(NAME unit-test COMMAND unit_testsuite)

#add_custom_command(unit
#        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
#        COMMAND $<TARGET_FILE:unit_testsuite>
#        #COMMAND ./unittests
#        COMMENT "Running unit test"
#        DEPENDS unittests
#        VERBATIM)

#add_custom_command(unitall
#    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
#    COMMAND $<TARGET_FILE:unit_testsuite> -s -a -r=compact
#    DEPENDS unittests)

#message(AUTHOR_WARNING "DEBUG: ${CMAKE_CURRENT_SOURCE_DIR}")
#message(AUTHOR_WARNING "DEBUG: ${PROJECT_SOURCE_DIR}")
#message(AUTHOR_WARNING "DEBUG: ${CATCH_INCLUDE_DIR}")
