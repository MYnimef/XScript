//
// Created by Ivan Markov on 12.04.2022.
//

#include "VarList.h"


VarList::VarList(const int& lineNum, const std::list<Var*>& value):
Var(lineNum, LIST_VAR),
value(value) {}

Var* VarList::operator + (const Var& second) const {
    auto list = getList();
    list.splice(list.end(), second.getList());
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

bool VarList::getBool() const {
    return !value.empty();
}

long long VarList::getInteger() const {
    return (long long) value.size();
}

long double VarList::getDouble() const {
    return (long double) value.size();
}

std::string VarList::getString() const {
    std::string result = "[";

    for (auto element: value) {
        result += element->getString() + ", ";
    }
    result.pop_back();
    result.pop_back();
    result += "]";

    return result;
}

std::list<Var*> VarList::getList() const {
    return value;
}
