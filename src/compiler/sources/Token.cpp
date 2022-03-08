//
// Created by Ivan Markov on 05.03.2022.
//

#include "Token.h"

Token::Token(const Type &type, const std::string& value)
: type(type), value(value) {

}

Token::~Token() {

}

Token::Token(const Token& token)
: type(token.type), value(token.value) {

}

EType Token::getType() {
    return type.getType();
}

std::string Token::getValue() {
    return value;
}

std::string Token::toString() {
    return "Token: " + type.toString() + ", Value: " + value;
}
