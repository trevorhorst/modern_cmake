cmake_minimum_required( VERSION 3.5 )
project( ModernCMake
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Modern CMake library"
    )

add_subdirectory( modern_cmake_core )
# add_subdirectory( modern_cmake_addon )
add_subdirectory( modern_cmake_app )
