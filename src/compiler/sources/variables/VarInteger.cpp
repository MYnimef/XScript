//
// Created by Ivan Markov on 08.04.2022.
//

#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"
#include "VarList.h"
#include "ExcVar.h"

VarInteger::VarInteger(const int& lineNum, long long value):
Var(lineNum),
value(value) {
    type = INTEGER_VAR;
}

Var* VarInteger::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() + second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() + second.getDouble());
        case LIST_VAR: {
            auto list = getList();
            list.splice(list.end(), second.getList());
            return new VarList(lineNum, list);
        }
        case STRING_VAR:
            return new VarString(lineNum, getString() + second.getString());
    }
}

Var* VarInteger::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() - second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() - second.getDouble());
        case LIST_VAR:
            throw ExcVar("wrong operand '-' for type 'list' at line " + std::to_string(lineNum));
        case STRING_VAR:
            throw ExcVar("wrong operand '-' for type 'string' at line " + std::to_string(lineNum));
    }
}

Var* VarInteger::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger(lineNum, getInteger() * second.getInteger());
        case DOUBLE_VAR:
            return new VarDouble(lineNum, getDouble() * second.getDouble());
        case LIST_VAR:
            throw ExcVar("wrong operand '*' for type 'list' at line " + std::to_string(lineNum));
        case STRING_VAR: {
            auto str = second.getString();
            std::string result;
            for (int i = 0; i < getInteger(); i++) {
                result += str;
            }
            return new VarString(lineNum, result);
        }
    }
}

Var* VarInteger::operator / (const Var& second) const {
    auto type = second.getType();
    if (type == STRING_VAR) {
        throw ExcVar("wrong operand '/' for type 'string' at line " + std::to_string(lineNum));
    } else if (type == LIST_VAR) {
        throw ExcVar("wrong operand '/' for type 'list' at line " + std::to_string(lineNum));
    } else {
        return new VarDouble(lineNum, getDouble() / second.getDouble());
    }
}

bool VarInteger::getBool() const {
    return (bool) value;
}

long long VarInteger::getInteger() const {
    return value;
}

long double VarInteger::getDouble() const {
    return (long double) value;
}

std::string VarInteger::getString() const {
    return std::to_string(value);
}

std::list<Var*> VarInteger::getList() const {
    return { new VarInteger(lineNum, value) };
}
