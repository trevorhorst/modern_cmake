cmake_minimum_required(VERSION 3.5)

project( ModernCMakeApp
    VERSION 0.0.1
    LANGUAGES C CXX
    DESCRIPTION "Modern cmake application example"
)

# Apparently this is the CONFIG mode signature, which means it will look for <Project>Config.cmake
# find_package( FawkesCore PATHS /home/trevorh/Projects/modern_cmake/modern_cmake_library/build )
# find_package( ModernCMakeCore )

add_executable( ${PROJECT_NAME} main.cpp )

# Try to stay away from variables, model requirements via properties 
# set( CMAKE_CXX_STANDARD 14 )
# set( CMAKE_CXX_STANDARD_REQUIRED ON )

# It's good practice to specify PUBLIC/PRIVATE when using target_*
target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
        -Wall 
        -Wextra 
        -pedantic
        -O3
)

target_compile_features(
    ${PROJECT_NAME}
    PRIVATE 
        cxx_std_14
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        ModernCMakeCore
    )
