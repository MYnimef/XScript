//
// Created by Ivan Markov on 08.04.2022.
//

#include "VariableBool.h"
#include "VariableInteger.h"
#include "VariableDouble.h"
#include "VariableString.h"

VariableBool::VariableBool(bool value):
value(value) {
    type = BOOL_VAR;
}

Variable *VariableBool::operator + (const Variable& second) {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VariableBool(getBool() || second.getBool());
        case INTEGER_VAR:
            return new VariableInteger(getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() + second.getDouble());
        case STRING_VAR:
            return new VariableString(getString() + second.getString());
    }
}

Variable *VariableBool::operator - (const Variable& second) {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VariableInteger(getInteger() - second.getInteger());
        case INTEGER_VAR:
            return new VariableInteger(getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() - second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Variable *VariableBool::operator * (const Variable& second) {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VariableInteger(getInteger() * second.getInteger());
        case INTEGER_VAR:
            return new VariableInteger(getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VariableDouble(getDouble() * second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Variable *VariableBool::operator / (const Variable& second) {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VariableDouble(getDouble() / second.getDouble());
    }
}

bool VariableBool::getBool() const {
    return value;
}

int VariableBool::getInteger() const {
    return (int) value;
}

double VariableBool::getDouble() const {
    return (double) value;
}

std::string VariableBool::getString() const {
    return (value ? "true" : "false");
}
