//
// Created by Ivan Markov on 08.03.2022.
//

#include "TokenType.h"

TokenType::TokenType(EType type)
: type(type) {

}

TokenType::~TokenType() {

}

EType TokenType::getType() {
    return type;
}

std::string TokenType::toString() {
    switch (type) {
        case ID:
            return "id pointer";
        case DOUBLE_DIGIT:
            return "double digit value";
        case INT_DIGIT:
            return "int digit value";
        case STRING:
            return "string value";
        case KEY_WORD:
            return "key word";
        case L_BRACKET:
            return "left bracket";
        case R_BRACKET:
            return "right bracket";
        case L_BRACE:
            return "left brace";
        case R_BRACE:
            return "right brace";
        case OPERATOR:
            return "operator";
        case SEMICOLON:
            return "semicolon";
    }
}

bool TokenType::operator <(const TokenType& another) const {
    return this->type < another.type;
}

