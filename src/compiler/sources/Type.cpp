//
// Created by Ivan Markov on 08.03.2022.
//

#include "Type.h"

Type::Type(EType type)
: type(type) {

}

Type::~Type() {

}

EType Type::getType() {
    return type;
}

std::string Type::toString() {
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

bool Type::operator <(const Type& another) const {
    return this->type < another.type;
}

