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
        return new VarString(lineNum, getString() + second.getString());
    } else if (type == LIST_VAR) {
        auto list = getList();
        list.splice(list.end(), second.getList());
        return new VarList(lineNum, list);
    } else {
        return new VarDouble(lineNum, getDouble() + second.getDouble());
    }
}

Var* VarDouble::operator - (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        second.throwExcOperator("-");
    } else {
        return new VarDouble(lineNum, getDouble() - second.getDouble());
    }
}

Var* VarDouble::operator * (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        second.throwExcOperator("*");
    } else {
        return new VarDouble(lineNum, getDouble() * second.getDouble());
    }
}

Var* VarDouble::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR || type == LIST_VAR) {
        second.throwExcOperator("/");
    } else {
        return new VarDouble(lineNum, getDouble() / second.getDouble());
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

std::list<Var*> VarDouble::getList() const {
    return { new VarDouble(lineNum, value) };
}
