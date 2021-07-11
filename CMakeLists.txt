cmake_minimum_required( VERSION 3.5 )
project( ModernCMake
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Modern CMake library"
    )

# Core library build
add_subdirectory( modern_cmake_core )

# Example application
if( BUILD_EXAMPLE_APP )
    add_subdirectory( modern_cmake_app )
endif()

# Optional add-on library
if( USE_ADDON )
    add_subdirectory( modern_cmake_addon )
endif()
