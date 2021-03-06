##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## CMake configuration file for the source files.
##

# configure version.cpp.in with selected version
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.cpp"
  )


##-----------------------------------------------------------------------------
## Libraries dependencies
##
find_package(Threads REQUIRED) #Threading


##-----------------------------------------------------------------------------
## Project's executable setup
##

# gather all *.cpp files
FILE(GLOB SRCS "*.cpp")

add_executable(${PROJECT_NAME}
    ${SRCS}
    ${CMAKE_CURRENT_BINARY_DIR}/version.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_THREAD_LIBS_INIT})


install(TARGETS ${PROJECT_NAME}
    DESTINATION bin)


add_custom_target(run
    WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin
    COMMAND ./${PROJECT_NAME}
    DEPENDS Install_)


#find_program()
#add_custom_target(run-dbg)
