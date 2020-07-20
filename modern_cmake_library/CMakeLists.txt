# Good practice to always provide a minimum required version
cmake_minimum_required( VERSION 3.5 )
# Project is required
project( FawkesCore
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Fawkes core library"
    )

# Append include files to the INCLUDE variable
set( INCLUDE ${INCLUDE}
    include/core/core.h
    )

# Append source files to the SOURCE variable
set( SOURCE ${SOURCE}
    src/core.cpp
    )

# Add INCLUDE and SOURCE contents to the target
add_library(
    ${PROJECT_NAME}
    SHARED
        ${INCLUDE}
        ${SOURCE}
    )

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER ${INCLUDE}
    )

# Specifies include directories to use when compiling a given target
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

set( INSTALL_DIR "$ENV{PWD}" )

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Config
    # Just trying to install to "lib" or "bin" doesn't act as I expected. It looks
    # like you need a full path hence the "$ENV{PWD}
    LIBRARY DESTINATION "${INSTALL_DIR}/lib"
    ARCHIVE DESTINATION "${INSTALL_DIR}/lib"
    RUNTIME DESTINATION "${INSTALL_DIR}/bin"
    PUBLIC_HEADER DESTINATION "${INSTALL_DIR}/include"
    # INCLUDES DESTINATION "$ENV{PWD}/include"
    )
#
# # install(FILES test.h DESTINATION include)
#
# include(CMakePackageConfigHelpers)
# write_basic_package_version_file(
#     ${PROJECT_NAME}ConfigVersion.cmake
#     VERSION ${PACKAGE_VERSION}
#     COMPATIBILITY AnyNewerVersion
#     )
#

configure_file(FawkesCore.pc.in FawkesCore.pc @ONLY)
message( "Directory: ${CMAKE_BINARY_DIR}" )
install(
    FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION $ENV{PWD}/pkgconfig)

install(
    EXPORT
        ${PROJECT_NAME}Config
    DESTINATION
        "${INSTALL_DIR}/share/${PROJECT_NAME}/cmake"
        )

export(
    TARGETS
        ${PROJECT_NAME}
    NAMESPACE
        Fawkes::
    FILE
        "${PROJECT_NAME}Config.cmake")
