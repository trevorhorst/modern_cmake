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

# Sets the version property for the target library
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        # EXPORT_NAME ${PROJECT_NAME} # This sets the name of the export, in this case t
        # PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include
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

# Installation instructions

include(GNUInstallDirs)

# set( INSTALL_DIR "$ENV{PWD}" )

install(
    TARGETS ${PROJECT_NAME}
    # EXPORT ${PROJECT_NAME}Config
    #     DESTINATION "share/${PROJECT_NAME}/cmake"
    # CMake defined library directories
    LIBRARY
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    # CMake defined binary directories
    RUNTIME
        DESTINATION "${CMAKE_INSTALL_BINDIR}"
    # PUBLIC_HEADER
    #     DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/include"
    )

# Use this to rename the exported name file
# set_target_properties(
#     ${PROJECT_NAME}
#     PROPERTIES
#         EXPORT_NAME JSONUtils
#     )

# Installs the include directory to the desired directory
install(
    DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )

# install(
#     EXPORT ${PROJECT_NAME}Config
#         DESTINATION "share/${PROJECT_NAME}/cmake"
#     )

# This include is required for the version file
include( CMakePackageConfigHelpers )
write_basic_package_version_file(
    ${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
    )


# configure_file(FawkesCore.pc.in FawkesCore.pc @ONLY)
# message( "Directory: ${CMAKE_BINARY_DIR}" )
# install(
#     FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
#     DESTINATION $ENV{PWD}/pkgconfig)

# This makes sure we just export the target. I think this is only done locally,
# in contrast the install will place it in the destinations you tell it to
export(
    TARGETS
        ${PROJECT_NAME}
    FILE
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    NAMESPACE
        Fawkes::
    )

export(
    PACKAGE
        ${PROJECT_NAME}
    )
