cmake_minimum_required(VERSION 3.21)
project(dsl)

set(CMAKE_CXX_STANDARD 23)

include_directories(src/compiler/headers)

add_executable(
        dsl

        src/compiler/main.cpp

        src/compiler/headers/Token.h
        src/compiler/sources/Token.cpp

        src/compiler/headers/Lexer.h
        src/compiler/sources/Lexer.cpp

        src/compiler/headers/Parser.h
        src/compiler/sources/Parser.cpp

        src/compiler/headers/Node.h
        src/compiler/sources/Node.cpp

        src/compiler/headers/Compiler.h
        src/compiler/sources/Compiler.cpp

        src/compiler/headers/Variable.h
        src/compiler/sources/Variable.cpp

        src/compiler/headers/Expression.h
        src/compiler/sources/Expression.cpp

        src/compiler/headers/ExpressionValInteger.h
        src/compiler/sources/ExpressionValInteger.cpp

        src/compiler/sources/ExpressionValString.cpp
        src/compiler/headers/ExpressionValString.h

        src/compiler/sources/ExpressionValDouble.cpp
        src/compiler/headers/ExpressionValDouble.h

        src/compiler/sources/ExpressionOpSum.cpp
        src/compiler/headers/ExpressionOpSum.h

        src/compiler/sources/ExpressionOpSub.cpp
        src/compiler/headers/ExpressionOpSub.h

        src/compiler/sources/ExpressionOpMult.cpp
        src/compiler/headers/ExpressionOpMult.h

        src/compiler/sources/ExpressionOpDiv.cpp
        src/compiler/headers/ExpressionOpDiv.h

        src/compiler/sources/ExpressionVarInit.cpp
        src/compiler/headers/ExpressionVarInit.h

        src/compiler/sources/ExpressionVarCall.cpp
        src/compiler/headers/ExpressionVarCall.h

        src/compiler/sources/ExpressionOpAssignment.cpp
        src/compiler/headers/ExpressionOpAssignment.h

        src/compiler/sources/ExpressionFunctionCall.cpp
        src/compiler/headers/ExpressionFunctionCall.h
)
