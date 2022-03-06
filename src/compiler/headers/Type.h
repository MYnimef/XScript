//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

enum Type {
    ID,
    DOUBLE_DIGIT,
    INT_DIGIT,
    STRING,
    IF_KW,
    ELSE_KW,
    FUNC_KW,
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    ASSIGN_OP,
    PLUS_OP,
    MINUS_OP,
    MULTIPLY_OP,
    DIVIDE_OP,
};

static std::string typeToString(const Type& type) {
    switch (type) {
        case ID:
            return "id pointer";
        case DOUBLE_DIGIT:
            return "double digit value";
        case INT_DIGIT:
            return "int digit value";
        case STRING:
            return "string value";
        case IF_KW:
            return "if key word";
        case ELSE_KW:
            return "else key word";
        case FUNC_KW:
            return "function key word";
        case L_BRACKET:
            return "left bracket";
        case R_BRACKET:
            return "right bracket";
        case L_BRACE:
            return "left brace";
        case R_BRACE:
            return "right brace";
        case ASSIGN_OP:
            return "assign operator";
        case PLUS_OP:
            return "plus operator";
        case MINUS_OP:
            return "minus operator";
        case MULTIPLY_OP:
            return "multiply operator";
        case DIVIDE_OP:
            return "divide operator";
    }
}
