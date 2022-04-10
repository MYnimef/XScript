//
// Created by Ivan Markov on 08.04.2022.
//

#include "VariableString.h"
#include "VariableBool.h"

VariableString::VariableString(const std::string& value):
value(value) {
    type = STRING_VAR;
}

Variable* VariableString::operator + (const Variable& second) const {
    return new VariableString(getString() + second.getString());
}

Variable* VariableString::operator - (const Variable& second) const {
    throw std::overflow_error("wrong operand for type string");
}

Variable* VariableString::operator * (const Variable& second) const {
    if (second.getType() == INTEGER_VAR) {
        auto str = getString();
        std::string result;
        for (int i = 0; i < second.getInteger(); i++) {
            result += str;
        }
        return new VariableString(result);
    } else {
        throw std::overflow_error("wrong operand for type string");
    }
}

Variable* VariableString::operator / (const Variable& second) const {
    throw std::overflow_error("wrong operand for type string");
}

bool VariableString::getBool() const {
    return !value.empty();
}

long long VariableString::getInteger() const {
    return std::stoll(value);
}

long double VariableString::getDouble() const {
    return std::stold(value);
}

std::string VariableString::getString() const {
    return value;
}
