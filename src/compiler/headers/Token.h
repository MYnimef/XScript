//
// Created by Ivan Markov on 05.03.2022.
//

#pragma once

#include <string>
#include "Type.h"

class Token final {
private:
    Type type;
    std::string value;

public:
    Token(const Type&, const std::string&);
    ~Token();
    Token(const Token&);

    EType getType();
    std::string getValue();

    std::string toString();
};
