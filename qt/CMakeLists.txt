cmake_minimum_required(VERSION 3.23)
project(dsl_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(dsl_qt main.cpp)
target_link_libraries(dsl_qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

include(${CMAKE_CURRENT_SOURCE_DIR}/../core/CMakeLists.txt)
target_link_libraries(dsl_qt dsl_core)
