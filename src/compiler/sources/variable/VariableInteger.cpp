//
// Created by Ivan Markov on 08.04.2022.
//

#include "VariableInteger.h"
#include "VariableDouble.h"
#include "VariableString.h"
#include "VariableBool.h"

VariableInteger::VariableInteger(long long value):
value(value) {
    type = INTEGER_VAR;
}

Variable* VariableInteger::operator + (const Variable& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VariableInteger(getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() + second.getDouble());
        case STRING_VAR:
            return new VariableString(getString() + second.getString());
    }
}

Variable* VariableInteger::operator - (const Variable& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VariableInteger(getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() - second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Variable* VariableInteger::operator * (const Variable& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VariableInteger(getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() * second.getDouble());
        case STRING_VAR: {
            auto str = second.getString();
            std::string result;
            for (int i = 0; i < getInteger(); i++) {
                result += str;
            }
            return new VariableString(result);
        }
    }
}

Variable* VariableInteger::operator / (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VariableDouble(getDouble() / second.getDouble());
    }
}

bool VariableInteger::getBool() const {
    return (bool) value;
}

long long VariableInteger::getInteger() const {
    return value;
}

long double VariableInteger::getDouble() const {
    return (long double) value;
}

std::string VariableInteger::getString() const {
    return std::to_string(value);
}
