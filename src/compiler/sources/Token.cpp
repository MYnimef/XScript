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

EType Token::getType() const {
    return type.getType();
}

std::string Token::getValue() const {
    return value;
}

std::string Token::toString() {
    return "Token: " + type.toString() + ", Value: " + value;
}
