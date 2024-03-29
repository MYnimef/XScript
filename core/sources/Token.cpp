//
// Created by Ivan Markov on 05.03.2022.
//

#include "Token.h"

Token::Token(const TokenType &type, const std::string& value, const int& lineNum):
type(type),
value(value),
lineNum(lineNum) {}

Token::Token(const Token& token):
type(token.type),
value(token.value),
lineNum(token.lineNum) {}

Token::~Token() = default;

TokenType Token::getType() const {
    return type;
}

std::string Token::getValue() const {
    return value;
}

int Token::getLineNum() const {
    return lineNum;
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
        case BREAK_KW:
            return "break";
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
        case MOD_OP:
            return "%";
        case COMMA:
            return ",";
        case SEMICOLON:
            return ";";
        case OR_OP:
            return "|";
        case AND_OP:
            return "&";
        case GREATER_OP:
            return ">";
        case SMALLER_OP:
            return "<";
        case GREATER_OR_EQUAL_OP:
            return "G";
        case SMALLER_OR_EQUAL_OP:
            return "S";
        case EQUAL_OP:
            return "E";
        case NOT_EQUAL_OP:
            return "N";
        case NOT_OP:
            return "!";
    }
}

bool Token::isOperator() const {
    return (
            type == ASSIGN_OP ||
            type == SUM_OP ||
            type == SUB_OP ||
            type == MULT_OP ||
            type == DIV_OP ||
            type == MOD_OP ||
            type == EQUAL_OP ||
            type == NOT_EQUAL_OP ||
            type == SMALLER_OP ||
            type == GREATER_OP ||
            type == SMALLER_OR_EQUAL_OP ||
            type == GREATER_OR_EQUAL_OP ||
            type == AND_OP ||
            type == OR_OP ||
            type == NOT_OP
            );
}

bool Token::isKeyWord() const {
    return (
            type == FUNC_KW ||
            type == IF_KW ||
            type == WHILE_KW ||
            type == BREAK_KW
            );
}
