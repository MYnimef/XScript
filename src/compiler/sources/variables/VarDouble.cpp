//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarDouble.h"
#include "VarString.h"

VarDouble::VarDouble(long double value):
value(value) {
    type = DOUBLE_VAR;
}

Var* VarDouble::operator + (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarString(getString() + second.getString());
    } else {
        return new VarDouble(getDouble() + second.getDouble());
    }
}

Var* VarDouble::operator - (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VarDouble(getDouble() - second.getDouble());
    }
}

Var* VarDouble::operator * (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VarDouble(getDouble() * second.getDouble());
    }
}

Var* VarDouble::operator / (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw std::overflow_error("wrong operand for type string");
    } else {
        return new VarDouble(getDouble() / second.getDouble());
    }
}

bool VarDouble::getBool() const {
    return (bool) value;
}

long long VarDouble::getInteger() const {
    return (long long) value;
}

long double VarDouble::getDouble() const {
    return value;
}

std::string VarDouble::getString() const {
    return std::to_string(value);
}
