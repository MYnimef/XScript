//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarList.h"


VarInteger::VarInteger(const int& lineNum, long long value):
Var(lineNum, INTEGER_VAR),
value(value) {}

Var* VarInteger::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, (long long) *this + (long long) second);
        case DOUBLE_VAR:
            return new VarDouble(lineNum, (long double) *this  + (long double) second);
        case LIST_VAR: {
            auto list = (std::list<Var*>) *this;
            list.splice(list.end(), (std::list<Var*>) second);
            return new VarList(lineNum, list);
        }
        case STRING_VAR:
            return new VarString(lineNum, (std::string) *this + (std::string) second);
    }
}

Var* VarInteger::operator - (const Var& second) const {
    const auto& type = second.getType();

    if (type == BOOL_VAR || type == INTEGER_VAR) {
        return new VarInteger(lineNum, (long long) *this - (long long) second);
    } else if (type == DOUBLE_VAR) {
        return new VarDouble(lineNum, (long double) *this - (long double) second);
    } else {
        return second.operator - (*this);
    }
}

Var* VarInteger::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, (long long) *this * (long long) second);
        case DOUBLE_VAR:
            return new VarDouble(lineNum, (long double) *this * (long double) second);
        case LIST_VAR:
            return second.operator * (*this);
        case STRING_VAR: {
            auto str = (std::string) second;
            std::string result;
            for (int i = 0; i < (long long) *this; i++) {
                result += str;
            }
            return new VarString(lineNum, result);
        }
    }
}

Var* VarInteger::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble(lineNum, (long double) *this / (long double) second);
    }
}

Var* VarInteger::operator % (const Var& second) const {
    const auto& type = second.getType();
    if (type == INTEGER_VAR) {
        return new VarInteger(lineNum, (long double) *this / (long double) second);
    } else {
        return super::operator % (second);
    }
}

VarInteger::operator bool() const {
    return (bool) value;
}

VarInteger::operator long long() const {
    return value;
}

VarInteger::operator long double() const {
    return (long double) value;
}

VarInteger::operator std::string() const {
    return std::to_string(value);
}

Var *VarInteger::copy(const int& lineNum) const {
    return new VarInteger(lineNum, value);
}
