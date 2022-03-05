cmake_minimum_required(VERSION 3.21)
project(dsl)

set(CMAKE_CXX_STANDARD 23)

add_executable(dsl source/main.cpp source/Token.cpp source/Token.h source/Type.h source/Lexer.cpp source/Lexer.h)
