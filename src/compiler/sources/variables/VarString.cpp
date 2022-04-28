//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarString.h"
#include "VarList.h"


VarString::VarString(const int& lineNum, const std::string& value):
Var(lineNum, STRING_VAR),
value(value) {}

Var* VarString::operator + (const Var& second) const {
    if (second.getType() == LIST_VAR) {
        auto list = (std::list<Var*>) *this;
        list.splice(list.end(), (std::list<Var*>) second);
        return new VarList(lineNum, list);
    } else {
        return new VarString(lineNum, (std::string) *this + (std::string) second);
    }
}

Var* VarString::operator - (const Var& second) const {
    return super::operator - (second);
}

Var* VarString::operator * (const Var& second) const {
    if (second.getType() == INTEGER_VAR) {
        auto str = (std::string) *this;
        std::string result;
        for (int i = 0; i < (long long) second; i++) {
            result += str;
        }
        return new VarString(lineNum, result);
    } else {
        return super::operator * (second);
    }
}

Var* VarString::operator / (const Var& second) const {
    return super::operator/(second);
}

VarString::operator bool() const {
    return !value.empty();
}

VarString::operator long long() const {
    try {
        return std::stoll(value);
    } catch (const std::exception& ex) {
        return super::operator long long();
    }
}

VarString::operator long double() const {
    try {
        return std::stold(value);
    } catch (const std::exception& ex) {
        return super::operator long double();
    }
}

VarString::operator std::string() const {
    return value;
}

Var *VarString::copy(const int& lineNum) const {
    return new VarString(lineNum, value);
}
