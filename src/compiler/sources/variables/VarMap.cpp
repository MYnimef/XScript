//
// Created by Ivan Markov on 27.04.2022.
//

#include "VarMap.h"

VarMap::VarMap(const int &lineNum, const std::map<Var*, Var*>& value):
Var(lineNum, MAP_VAR),
value(value) {}

Var* VarMap::operator + (const Var& second) const {
    return super::operator + (second);
}

Var* VarMap::operator - (const Var& second) const {
    return super::operator - (second);
}

Var* VarMap::operator * (const Var& second) const {
    return super::operator * (second);
}

Var* VarMap::operator / (const Var& second) const {
    return super::operator / (second);
}

bool VarMap::getBool() const {
    return super::getBool();
}

long long VarMap::getInteger() const {
    return super::getInteger();
}

long double VarMap::getDouble() const {
    return super::getDouble();
}

std::string VarMap::getString() const {
    std::string result = "{";

    for (auto element: value) {
        auto key = element.first;
        auto val = element.second;

        result += " { " + key->getString() + " : " + val->getString() + " },";
    }

    result.pop_back();
    result += " }";

    return result;
}

std::list<Var *> VarMap::getList() const {
    return { new VarMap(lineNum, value) };
}

std::map<Var *, Var *> VarMap::getMap() const {
    return value;
}
