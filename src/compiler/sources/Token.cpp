//
// Created by Ivan Markov on 05.03.2022.
//

#include "Token.h"

Token::Token(const Type &type, const std::string& value)
: type(type), value(value) {

}

std::string Token::toString() {
    return "Token: " + typeToString(type) + ", Value: " + value;
}
