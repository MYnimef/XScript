cmake_minimum_required(VERSION 3.21)
project(dsl)

set(CMAKE_CXX_STANDARD 23)

include_directories(src/compiler/headers)
include_directories(src/compiler/headers/exceptions)
include_directories(src/compiler/headers/expressions)
include_directories(src/compiler/headers/variables)
include_directories(src/compiler/headers/functions)

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

        src/compiler/headers/variables/Var.h
        src/compiler/sources/variables/Var.cpp

        src/compiler/headers/variables/VarInteger.h
        src/compiler/sources/variables/VarInteger.cpp

        src/compiler/headers/variables/VarDouble.h
        src/compiler/sources/variables/VarDouble.cpp

        src/compiler/headers/variables/VarString.h
        src/compiler/sources/variables/VarString.cpp

        src/compiler/headers/variables/VarBool.h
        src/compiler/sources/variables/VarBool.cpp

        src/compiler/headers/variables/VarList.h
        src/compiler/sources/variables/VarList.cpp

        src/compiler/headers/expressions/Exp.h
        src/compiler/sources/expressions/Exp.cpp

        src/compiler/headers/expressions/ExpValInteger.h
        src/compiler/sources/expressions/ExpValInteger.cpp

        src/compiler/headers/expressions/ExpValString.h
        src/compiler/sources/expressions/ExpValString.cpp

        src/compiler/headers/expressions/ExpValDouble.h
        src/compiler/sources/expressions/ExpValDouble.cpp

        src/compiler/headers/expressions/ExpOpSum.h
        src/compiler/sources/expressions/ExpOpSum.cpp

        src/compiler/headers/expressions/ExpOpSub.h
        src/compiler/sources/expressions/ExpOpSub.cpp

        src/compiler/headers/expressions/ExpOpMult.h
        src/compiler/sources/expressions/ExpOpMult.cpp

        src/compiler/headers/expressions/ExpOpDiv.h
        src/compiler/sources/expressions/ExpOpDiv.cpp

        src/compiler/headers/expressions/ExpOpAssignVar.h
        src/compiler/sources/expressions/ExpOpAssignVar.cpp

        src/compiler/headers/expressions/ExpVarCall.h
        src/compiler/sources/expressions/ExpVarCall.cpp

        src/compiler/headers/expressions/ExpFuncCall.h
        src/compiler/sources/expressions/ExpFuncCall.cpp

        src/compiler/headers/expressions/ExpValBool.h
        src/compiler/sources/expressions/ExpValBool.cpp

        src/compiler/headers/expressions/ExpBlockIf.h
        src/compiler/sources/expressions/ExpBlockIf.cpp

        src/compiler/headers/expressions/ExpLogicalSmaller.h
        src/compiler/sources/expressions/ExpLogicalSmaller.cpp

        src/compiler/headers/expressions/ExpLogicalSmallerOrEqual.h
        src/compiler/sources/expressions/ExpLogicalSmallerOrEqual.cpp

        src/compiler/headers/expressions/ExpLogicalGreater.h
        src/compiler/sources/expressions/ExpLogicalGreater.cpp

        src/compiler/headers/expressions/ExpLogicalGreaterOrEqual.h
        src/compiler/sources/expressions/ExpLogicalGreaterOrEqual.cpp

        src/compiler/headers/expressions/ExpLogicalEqual.h
        src/compiler/sources/expressions/ExpLogicalEqual.cpp

        src/compiler/headers/expressions/ExpLogicalNotEqual.h
        src/compiler/sources/expressions/ExpLogicalNotEqual.cpp

        src/compiler/headers/expressions/ExpLogicalOr.h
        src/compiler/sources/expressions/ExpLogicalOr.cpp

        src/compiler/headers/expressions/ExpLogicalAnd.h
        src/compiler/sources/expressions/ExpLogicalAnd.cpp

        src/compiler/headers/expressions/ExpLogicalNot.h
        src/compiler/sources/expressions/ExpLogicalNot.cpp

        src/compiler/headers/exceptions/ExcParser.h
        src/compiler/sources/exceptions/ExcParser.cpp

        src/compiler/headers/exceptions/ExcLexer.h
        src/compiler/sources/exceptions/ExcLexer.cpp

        src/compiler/headers/expressions/ExpBlockWhile.h
        src/compiler/sources/expressions/ExpBlockWhile.cpp

        src/compiler/headers/expressions/ExpBlock.h
        src/compiler/sources/expressions/ExpBlock.cpp

        src/compiler/headers/expressions/ExpFuncDef.h
        src/compiler/sources/expressions/ExpFuncDef.cpp

        src/compiler/headers/expressions/ExpOpAssignVarFunc.h
        src/compiler/sources/expressions/ExpOpAssignVarFunc.cpp

        src/compiler/headers/expressions/ExpFuncCustom.h
        src/compiler/sources/expressions/ExpFuncCustom.cpp

        src/compiler/headers/functions/FuncPrint.h
        src/compiler/sources/functions/FuncPrint.cpp

        src/compiler/headers/functions/FuncPrintln.h
        src/compiler/sources/functions/FuncPrintln.cpp

        src/compiler/headers/exceptions/ExcVar.h
        src/compiler/sources/exceptions/ExcVar.cpp

        src/compiler/headers/exceptions/ExcExp.h
        src/compiler/sources/exceptions/ExcExp.cpp
)
