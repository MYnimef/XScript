//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>
#include "Type.h"

class Token {
public:
    Token(const Type &type, const std::string& value);
    std::string toString();

private:
    Type type;
    std::string value;

};
