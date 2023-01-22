//
// Created by Ivan Markov on 12.04.2022.
//

#include "VarList.h"


VarList::VarList(const int& lineNum, const std::list<Var*>& value):
Var(lineNum, LIST_VAR),
value(value) {}

Var* VarList::operator + (const Var& second) const {
    auto list = (std::list<Var*>) *this;
    list.splice(list.end(), (std::list<Var*>) second);
    return new VarList(lineNum, list);
}

Var* VarList::operator - (const Var& second) const {
    return super::operator - (second);
}

Var* VarList::operator * (const Var& second) const {
    return super::operator * (second);
}

Var* VarList::operator / (const Var& second) const {
    return super::operator / (second);
}

Var* VarList::operator % (const Var& second) const {
    return super::operator % (second);
}

VarList::operator bool() const {
    return !value.empty();
}

VarList::operator long long() const {
    return (long long) value.size();
}

VarList::operator long double() const {
    return (long double) value.size();
}

VarList::operator std::string() const {
    std::string result = "[";
    if (!value.empty()) {
        for (auto element: value) {
            result += (std::string) *element + ", ";
        }
        result.pop_back();
        result.pop_back();
    }
    result += "]";

    return result;
}

VarList::operator std::list<Var*>() const {
    return value;
}

Var *VarList::copy(const int& lineNum) const {
    return new VarList(lineNum, value);
}
