//
// Created by Ivan Markov on 08.04.2022.
//

#include "VariableInteger.h"
#include "VariableDouble.h"
#include "VariableString.h"

VariableInteger::VariableInteger(int value):
value(value) {
    type = INTEGER_VAR;
}

Variable* VariableInteger::operator + (const Variable& second) {
    switch (second.getType()) {
        case INTEGER_VAR:
            return new VariableInteger(getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() + second.getDouble());
        case STRING_VAR:
            return new VariableString(getString() + second.getString());
    }
}

Variable* VariableInteger::operator - (const Variable& second) {
    switch (second.getType()) {
        case INTEGER_VAR:
            return new VariableInteger(getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() - second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Variable* VariableInteger::operator * (const Variable& second) {
    switch (second.getType()) {
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

Variable* VariableInteger::operator / (const Variable& second) {
    switch (second.getType()) {
        case INTEGER_VAR:
            return new VariableDouble(getDouble() / second.getDouble());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() / second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

int VariableInteger::getInteger() const {
    return value;
}

double VariableInteger::getDouble() const {
    return (double) value;
}

std::string VariableInteger::getString() const {
    return std::to_string(value);
}
