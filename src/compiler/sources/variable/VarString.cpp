//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarString.h"
#include "VarBool.h"

VarString::VarString(const std::string& value):
value(value) {
    type = STRING_VAR;
}

Var* VarString::operator + (const Var& second) const {
    return new VarString(getString() + second.getString());
}

Var* VarString::operator - (const Var& second) const {
    throw std::overflow_error("wrong operand for type string");
}

Var* VarString::operator * (const Var& second) const {
    if (second.getType() == INTEGER_VAR) {
        auto str = getString();
        std::string result;
        for (int i = 0; i < second.getInteger(); i++) {
            result += str;
        }
        return new VarString(result);
    } else {
        throw std::overflow_error("wrong operand for type string");
    }
}

Var* VarString::operator / (const Var& second) const {
    throw std::overflow_error("wrong operand for type string");
}

bool VarString::getBool() const {
    return !value.empty();
}

long long VarString::getInteger() const {
    return std::stoll(value);
}

long double VarString::getDouble() const {
    return std::stold(value);
}

std::string VarString::getString() const {
    return value;
}
