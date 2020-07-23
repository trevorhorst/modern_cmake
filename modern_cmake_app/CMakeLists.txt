cmake_minimum_required(VERSION 3.5)

project(app
    VERSION 0.0.1
    LANGUAGES C CXX
    DESCRIPTION "Modern cmake application example"
    )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package( FawkesCore PATHS /home/trevorh/Projects/modern_cmake/modern_cmake_library/build )
# find_package( FawkesCore )

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    FawkesCore
    )
