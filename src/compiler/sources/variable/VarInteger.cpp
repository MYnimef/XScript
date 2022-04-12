//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarBool.h"

VarInteger::VarInteger(long long value):
value(value) {
    type = INTEGER_VAR;
}

Var* VarInteger::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() + second.getDouble());
        case STRING_VAR:
            return new VarString(getString() + second.getString());
    }
}

Var* VarInteger::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() - second.getDouble());
        case STRING_VAR:
            throw std::overflow_error("wrong operand for type string");
    }
}

Var* VarInteger::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(getDouble() * second.getDouble());
        case STRING_VAR: {
            auto str = second.getString();
            std::string result;
            for (int i = 0; i < getInteger(); i++) {
                result += str;
            }
            return new VarString(result);
        }
    }
}

Var* VarInteger::operator / (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VarDouble(getDouble() / second.getDouble());
    }
}

bool VarInteger::getBool() const {
    return (bool) value;
}

long long VarInteger::getInteger() const {
    return value;
}

long double VarInteger::getDouble() const {
    return (long double) value;
}

std::string VarInteger::getString() const {
    return std::to_string(value);
}
