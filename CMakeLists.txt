cmake_minimum_required(VERSION 3.21)
project(dsl)

set(CMAKE_CXX_STANDARD 23)

include_directories(src/compiler/headers)

add_executable(
        dsl

        src/compiler/main.cpp

        src/compiler/sources/Token.cpp
        src/compiler/headers/Token.h

        src/compiler/headers/Type.h
        src/compiler/sources/Type.cpp

        src/compiler/sources/Lexer.cpp
        src/compiler/headers/Lexer.h

        src/compiler/headers/Parser.h
        src/compiler/sources/Parser.cpp

        src/compiler/headers/Node.h
        src/compiler/sources/Node.cpp
)
