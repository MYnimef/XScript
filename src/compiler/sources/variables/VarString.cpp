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
        auto list = getList();
        list.splice(list.end(), second.getList());
        return new VarList(lineNum, list);
    } else {
        return new VarString(lineNum, getString() + second.getString());
    }
}

Var* VarString::operator - (const Var& second) const {
    return super::operator - (second);
}

Var* VarString::operator * (const Var& second) const {
    if (second.getType() == INTEGER_VAR) {
        auto str = getString();
        std::string result;
        for (int i = 0; i < second.getInteger(); i++) {
            result += str;
        }
        return new VarString(lineNum, result);
    } else {
        return super::operator * (second);
    }
}

Var* VarString::operator / (const Var& second) const {
    return super::operator / (second);
}

bool VarString::getBool() const {
    return !value.empty();
}

long long VarString::getInteger() const {
    try {
        return std::stoll(value);
    } catch (const std::exception& ex) {
        throwExcConvert(getString(), "'int'");
    }
}

long double VarString::getDouble() const {
    try {
        return std::stold(value);
    } catch (const std::exception& ex) {
        throwExcConvert(getString(), "'float'");
    }
}

std::string VarString::getString() const {
    return value;
}

std::list<Var*> VarString::getList() const {
    return { new VarString(lineNum, value) };
}
