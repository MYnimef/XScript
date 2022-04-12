//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarBool.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "ExcVar.h"
#include "VarList.h"

VarBool::VarBool(const int& lineNum, bool value):
Var(lineNum),
value(value) {
    type = BOOL_VAR;
}

Var* VarBool::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarBool(lineNum, getBool() || second.getBool());
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() + second.getDouble());
        case STRING_VAR:
            return new VarString(lineNum, getString() + second.getString());
        case LIST_VAR: {
            auto list = getList();
            list.splice(list.end(), second.getList());
            return new VarList(lineNum, list);
        }
    }
}

Var* VarBool::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() - second.getDouble());
        case STRING_VAR:
            throw ExcVar("wrong operand '-' for type 'string'", lineNum);
        case LIST_VAR:
            throw ExcVar("wrong operand '-' for type 'list'", lineNum);
    }
}

Var* VarBool::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() * second.getDouble());
        case STRING_VAR:
            throw ExcVar("wrong operand '*' for type 'string'", lineNum);
        case LIST_VAR:
            throw ExcVar("wrong operand '*' for type 'list'", lineNum);
    }
}

Var* VarBool::operator / (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        throw ExcVar("wrong operand '/' for type 'string'", lineNum);
    } else if (second.getType() == LIST_VAR) {
        throw ExcVar("wrong operand '/' for type 'list'", lineNum);
    } else {
        return new VarDouble(lineNum, getDouble() / second.getDouble());
    }
}

bool VarBool::getBool() const {
    return value;
}

long long VarBool::getInteger() const {
    return (long long) value;
}

long double VarBool::getDouble() const {
    return (long double) value;
}

std::string VarBool::getString() const {
    return (value ? "true" : "false");
}

std::list<Var*> VarBool::getList() const {
    return { new VarBool(lineNum, value) };
}
