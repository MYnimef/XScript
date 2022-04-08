//
// Created by Ivan Markov on 05.03.2022.
//

#include "Token.h"

Token::Token(const TokenType &type, const std::string& value)
: type(type), value(value) {

}

Token::~Token() {

}

Token::Token(const Token& token)
: type(token.type), value(token.value) {

}

TokenType Token::getType() const {
    return type;
}

std::string Token::getValue() const {
    return value;
}

std::string Token::toString() const {
    return "Token: " + typeToString() + ", Value: " + value;
}

std::string Token::typeToString() const {
    switch (type) {
        case ID:
            return "@";
        case DOUBLE_DIGIT:
            return "d";
        case INT_DIGIT:
            return "i";
        case STRING:
            return "s";
        case BOOL:
            return "b";

        case FUNC_KW:
            return "func";
        case IF_KW:
            return "if";
        case ELSE_KW:
            return "else";
        case WHILE_KW:
            return "while";
        case FOR_KW:
            return "for";

        case L_BRACKET:
            return "(";
        case R_BRACKET:
            return ")";
        case L_BRACE:
            return "{";
        case R_BRACE:
            return "}";

        case INCREMENT_OP:
            return "I";
        case DECREMENT_OP:
            return "D";
        case ASSIGN_OP:
            return "=";
        case SUM_OP:
            return "+";
        case SUB_OP:
            return "-";
        case MULT_OP:
            return "*";
        case DIV_OP:
            return "/";

        case COMMA:
            return ",";
        case SEMICOLON:
            return ";";
        default:
            return "you shouldnt see this";
    }
}

bool Token::isOperator() const {
    return (
            type == ASSIGN_OP ||
            type == SUM_OP ||
            type == SUB_OP ||
            type == MULT_OP ||
            type == DIV_OP
            );
}

bool Token::isKeyWord() const {
    return (
            type == FUNC_KW ||
            type == IF_KW ||
            type == ELSE_KW ||
            type == WHILE_KW ||
            type == FOR_KW
            );
}
