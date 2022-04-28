//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarDouble.h"
#include "VarString.h"
#include "VarList.h"


VarDouble::VarDouble(const int& lineNum, long double value):
Var(lineNum, DOUBLE_VAR),
value(value) {}

Var* VarDouble::operator + (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return new VarString(lineNum, (std::string) *this + (std::string) second);
    } else if (type == LIST_VAR) {
        auto list = (std::list<Var*>) *this;
        list.splice(list.end(), (std::list<Var*>) second);
        return new VarList(lineNum, list);
    } else {
        return new VarDouble(lineNum, (long double) *this + (long double) second);
    }
}

Var* VarDouble::operator - (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        return second.operator - (*this);
    } else {
        return new VarDouble(lineNum, (long double) *this - (long double) second);
    }
}

Var* VarDouble::operator * (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        return second.operator * (*this);
    } else {
        return new VarDouble(lineNum, (long double) *this * (long double) second);
    }
}

Var* VarDouble::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble(lineNum, (long double) *this / (long double) second);
    }
}

VarDouble::operator bool() const {
    return (bool) value;
}

VarDouble::operator long long() const {
    return (long long) value;
}

VarDouble::operator long double() const {
    return value;
}

VarDouble::operator std::string() const {
    return std::to_string(value);
}

Var *VarDouble::copy(const int& lineNum) const {
    return new VarDouble(lineNum, value);
}
