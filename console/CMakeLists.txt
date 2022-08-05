cmake_minimum_required(VERSION 3.21)
project(dsl_console)

set(CMAKE_CXX_STANDARD 23)

include(${CMAKE_CURRENT_SOURCE_DIR}/../core/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/functions/CMakeLists.txt)

add_executable(dsl_console main.cpp)

target_link_libraries(dsl_console dsl_core)
target_link_libraries(dsl_console dsl_console_functions)