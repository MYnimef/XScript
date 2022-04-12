cmake_minimum_required(VERSION 3.21)
project(dsl)

set(CMAKE_CXX_STANDARD 23)

include_directories(src/compiler/headers)
include_directories(src/compiler/headers/exception)
include_directories(src/compiler/headers/expression)
include_directories(src/compiler/headers/variable)

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

        src/compiler/headers/CompilerArgs.h
        src/compiler/sources/CompilerArgs.cpp

        src/compiler/headers/variable/Var.h
        src/compiler/sources/variable/Var.cpp

        src/compiler/headers/variable/VarInteger.h
        src/compiler/sources/variable/VarInteger.cpp

        src/compiler/headers/variable/VarDouble.h
        src/compiler/sources/variable/VarDouble.cpp

        src/compiler/headers/variable/VarString.h
        src/compiler/sources/variable/VarString.cpp

        src/compiler/headers/variable/VarBool.h
        src/compiler/sources/variable/VarBool.cpp

        src/compiler/headers/variable/VarList.h

        src/compiler/headers/expression/Exp.h
        src/compiler/sources/expression/Exp.cpp

        src/compiler/headers/expression/ExpValInteger.h
        src/compiler/sources/expression/ExpValInteger.cpp

        src/compiler/headers/expression/ExpValString.h
        src/compiler/sources/expression/ExpValString.cpp

        src/compiler/headers/expression/ExpValDouble.h
        src/compiler/sources/expression/ExpValDouble.cpp

        src/compiler/headers/expression/ExpOpSum.h
        src/compiler/sources/expression/ExpOpSum.cpp

        src/compiler/headers/expression/ExpOpSub.h
        src/compiler/sources/expression/ExpOpSub.cpp

        src/compiler/headers/expression/ExpOpMult.h
        src/compiler/sources/expression/ExpOpMult.cpp

        src/compiler/headers/expression/ExpOpDiv.h
        src/compiler/sources/expression/ExpOpDiv.cpp

        src/compiler/headers/expression/ExpOpAssignVar.h
        src/compiler/sources/expression/ExpOpAssignVar.cpp

        src/compiler/headers/expression/ExpVarCall.h
        src/compiler/sources/expression/ExpVarCall.cpp

        src/compiler/headers/expression/ExpFuncCall.h
        src/compiler/sources/expression/ExpFuncCall.cpp

        src/compiler/headers/expression/ExpValBool.h
        src/compiler/sources/expression/ExpValBool.cpp

        src/compiler/headers/expression/ExpBlockIf.h
        src/compiler/sources/expression/ExpBlockIf.cpp

        src/compiler/headers/expression/ExpLogicalSmaller.h
        src/compiler/sources/expression/ExpLogicalSmaller.cpp

        src/compiler/headers/expression/ExpLogicalSmallerOrEqual.h
        src/compiler/sources/expression/ExpLogicalSmallerOrEqual.cpp

        src/compiler/headers/expression/ExpLogicalGreater.h
        src/compiler/sources/expression/ExpLogicalGreater.cpp

        src/compiler/headers/expression/ExpLogicalGreaterOrEqual.h
        src/compiler/sources/expression/ExpLogicalGreaterOrEqual.cpp

        src/compiler/headers/expression/ExpLogicalEqual.h
        src/compiler/sources/expression/ExpLogicalEqual.cpp

        src/compiler/headers/expression/ExpLogicalNotEqual.h
        src/compiler/sources/expression/ExpLogicalNotEqual.cpp

        src/compiler/headers/expression/ExpLogicalOr.h
        src/compiler/sources/expression/ExpLogicalOr.cpp

        src/compiler/headers/expression/ExpLogicalAnd.h
        src/compiler/sources/expression/ExpLogicalAnd.cpp

        src/compiler/headers/expression/ExpLogicalNot.h
        src/compiler/sources/expression/ExpLogicalNot.cpp

        src/compiler/headers/exception/ExcParser.h
        src/compiler/sources/exception/ExcParser.cpp

        src/compiler/headers/exception/ExcLexer.h
        src/compiler/sources/exception/ExcLexer.cpp

        src/compiler/headers/expression/ExpBlockWhile.h
        src/compiler/sources/expression/ExpBlockWhile.cpp

        src/compiler/headers/expression/ExpBlock.h
        src/compiler/sources/expression/ExpBlock.cpp

        src/compiler/headers/expression/ExpFuncDef.h
        src/compiler/sources/expression/ExpFuncDef.cpp

        src/compiler/headers/expression/ExpOpAssignVarFunc.h
        src/compiler/sources/expression/ExpOpAssignVarFunc.cpp
)
