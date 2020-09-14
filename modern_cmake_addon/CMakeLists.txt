cmake_minimum_required( VERSION 3.5 )

# find_package( ModernCMakeCore REQUIRED )

project( ModernCMakeAddOn
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Modern CMake add on library" 
    )

set( INCLUDE_ADDON ${INCLUDE_ADDON}
    include/addon/addon.h
    )

set( SOURCE_ADDON ${SOURCE_ADDON}
    src/addon.cpp
    )

add_library(
    ${PROJECT_NAME}
    SHARED
        ${INCLUDE_ADDON}
        ${SOURCE_ADDON}
    )

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        VERSION ${PROJECT_VERSION}
    )

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
