##-----------------------------------------------------------------------------
## Project:   sample-project
## Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
## License:   MIT, see the LICENSE file for more details
##
## Populate this directory with external projects used by this one
##

include(ExternalProject)
find_package(Git REQUIRED)



#------------------------------------------------------------------------------
# Catch - Unit test header-only library
#  *
ExternalProject_Add(
    Catch
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    )

# Update Catch target
add_custom_target(external-catch-update
    COMMENT "Updated Catch"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Catch/src/Catch
    COMMAND ${GIT_EXECUTABLE} pull
    DEPENDS Catch)

# expose required catch header path so it could be included where necessary
ExternalProject_Get_Property(Catch SOURCE_DIR)
set(CATCH_INCLUDE_DIR ${SOURCE_DIR}/single_include CACHE INTERNAL PARENT_SCOPE)


#------------------------------------------------------------------------------
# Convenience update all
add_custom_target(external-update-all
    COMMENT "Updated all external projects"
    DEPENDS external-Catch-update)
