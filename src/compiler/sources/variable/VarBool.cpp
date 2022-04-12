//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarBool.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"

VarBool::VarBool(bool value):
value(value) {
    type = BOOL_VAR;
}

Var* VarBool::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarBool(getBool() || second.getBool());
        case INTEGER_VAR:
            return new VarInteger(getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() + second.getDouble());
        case STRING_VAR:
            return new VarString(getString() + second.getString());
    }
}

Var* VarBool::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarInteger(getInteger() - second.getInteger());
        case INTEGER_VAR:
            return new VarInteger(getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() - second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Var* VarBool::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarInteger(getInteger() * second.getInteger());
        case INTEGER_VAR:
            return new VarInteger(getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() * second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Var* VarBool::operator / (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VarDouble(getDouble() / second.getDouble());
    }
}

bool VarBool::getBool() const {
    return value;
}

long long VarBool::getInteger() const {
    return (long long) value;
}

long double VarBool::getDouble() const {
    return (long double) value;
}

std::string VarBool::getString() const {
    return (value ? "true" : "false");
}
