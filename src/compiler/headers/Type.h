//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

enum Type {
    VAR,
    DIGIT,
    STRING,
    FUNC,
    IF_KW,
    ELSE_KW,
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    ASSIGN_OP,
};

static std::string typeToString(const Type& type) {
    switch (type) {
        case VAR:
            return "variable";
        case DIGIT:
            return "digit";
        case STRING:
            return "string";
        case FUNC:
            return "function";
        case IF_KW:
            return "if";
        case ELSE_KW:
            return "else";
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
    }
}
