//
// Created by Ivan Markov on 08.04.2022.
//

#include "VariableDouble.h"
#include "VariableString.h"

VariableDouble::VariableDouble(double value):
value(value) {
    type = DOUBLE_VAR;
}

Variable* VariableDouble::operator + (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        return new VariableString(getString() + second.getString());
    } else {
        return new VariableDouble(getDouble() + second.getDouble());
    }
}

Variable* VariableDouble::operator - (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VariableDouble(getDouble() - second.getDouble());
    }
}

Variable* VariableDouble::operator * (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VariableDouble(getDouble() * second.getDouble());
    }
}

Variable* VariableDouble::operator / (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VariableDouble(getDouble() / second.getDouble());
    }
}

bool VariableDouble::getBool() const {
    return (bool) value;
}

int VariableDouble::getInteger() const {
    return (int) value;
}

double VariableDouble::getDouble() const {
    return value;
}

std::string VariableDouble::getString() const {
    return std::to_string(value);
}
