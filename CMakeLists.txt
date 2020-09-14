cmake_minimum_required( VERSION 3.5 )
project( ModernCMake
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Modern CMake library"
    )

# Example application
add_subdirectory( modern_cmake_app )

# Core library build
add_subdirectory( modern_cmake_core )

# Optional add-on library
if( USE_ADDON )
    add_subdirectory( modern_cmake_addon )
endif()
