//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarBool.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarList.h"


VarBool::VarBool(const int& lineNum, bool value):
Var(lineNum, BOOL_VAR),
value(value) {}

Var* VarBool::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarBool(lineNum, (bool) *this || (bool) second);
        case INTEGER_VAR:
            return new VarInteger(lineNum, (long long) *this + (long long) second);
        case DOUBLE_VAR:
            return new VarDouble(lineNum, (long double) *this + (long double) second);
        case STRING_VAR:
            return new VarString(lineNum, (std::string) *this + (std::string) second);
        case LIST_VAR: {
            auto list = (std::list<Var*>) *this;
            list.splice(list.end(), (std::list<Var*>) second);
            return new VarList(lineNum, list);
        }
    }
}

Var* VarBool::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, (long long) *this - (long long) second);
        case DOUBLE_VAR:
            return new VarDouble(lineNum, (long double) *this - (long double) second);
        case STRING_VAR:
        case LIST_VAR:
            return second.operator - (*this);
    }
}

Var* VarBool::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum,(long long) *this * (long long) second);
        case DOUBLE_VAR:
            return new VarDouble(lineNum, (long double) *this * (long double) second);
        case STRING_VAR:
        case LIST_VAR:
            return second.operator * (*this);
    }
}

Var* VarBool::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble(lineNum, (long double) *this / (long double) second);
    }
}

VarBool::operator bool() const {
    return value;
}

VarBool::operator long long() const {
    return (long long) value;
}

VarBool::operator long double() const {
    return (long double) value;
}

VarBool::operator std::string() const {
    return (value ? "true" : "false");
}

Var *VarBool::copy(const int& lineNum) const {
    return new VarBool(lineNum, value);
}
