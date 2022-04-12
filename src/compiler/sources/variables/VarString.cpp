//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarString.h"
#include "VarBool.h"
#include "VarList.h"
#include "ExcVar.h"

VarString::VarString(const int& lineNum, const std::string& value):
Var(lineNum),
value(value) {
    type = STRING_VAR;
}

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
    throw ExcVar("wrong operand '-' for type 'string' at line " + std::to_string(lineNum));
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
        throw ExcVar("wrong operand '*' for type 'string' at line " + std::to_string(lineNum));
    }
}

Var* VarString::operator / (const Var& second) const {
    throw ExcVar("wrong operand '/' for type 'string' at line " + std::to_string(lineNum));
}

bool VarString::getBool() const {
    return !value.empty();
}

long long VarString::getInteger() const {
    return std::stoll(value);
}

long double VarString::getDouble() const {
    return std::stold(value);
}

std::string VarString::getString() const {
    return value;
}

std::list<Var*> VarString::getList() const {
    return { new VarString(lineNum, value) };
}
