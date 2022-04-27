//
// Created by Ivan Markov on 04.04.2022.
//

#include "Var.h"
#include "VarBool.h"
#include "ExcVar.h"


Var::Var(const int& lineNum, const VarType& type):
lineNum(lineNum),
type(type) {}

Var::~Var() {

}

std::string Var::getTypeName() const {
    switch (type) {
        case BOOL_VAR:
            return "'bool'";
        case INTEGER_VAR:
            return "'int'";
        case DOUBLE_VAR:
            return "'double'";
        case STRING_VAR:
            return "'string'";
        case LIST_VAR:
            return "'list'";
    }
}

void Var::throwExcOperator(const std::string& op) const {
    throw ExcVar("wrong operand '" + op + "' for type " + getTypeName(), lineNum);
}

void Var::throwExcConvert(const std::string& value, const std::string& typeName) const {
    throw ExcVar("unable to convert '" + value + "' to type " + typeName, lineNum);
}

Var* Var::operator + (const Var&) const {
    throwExcOperator("+");
}

Var* Var::operator - (const Var&) const {
    throwExcOperator("-");
}

Var* Var::operator * (const Var&) const {
    throwExcOperator("*");
}

Var* Var::operator / (const Var&) const {
    throwExcOperator("/");
}

Var* Var::operator ! () const {
    return new VarBool(lineNum, !getBool());
}

Var* Var::operator < (const Var& second) const {
    if (type == STRING_VAR || second.getType() == STRING_VAR) {
        return new VarBool(lineNum, getString().length() < second.getString().length());
    } else {
        return new VarBool(lineNum, getDouble() < second.getDouble());
    }
}

Var* Var::operator <= (const Var& second) const {
    if (type == STRING_VAR || second.getType() == STRING_VAR) {
        return new VarBool(lineNum, getString().length() <= second.getString().length());
    } else {
        return new VarBool(lineNum, getDouble() <= second.getDouble());
    }
}

Var* Var::operator > (const Var& second) const {
    if (type == STRING_VAR || second.getType() == STRING_VAR) {
        return new VarBool(lineNum, getString().length() > second.getString().length());
    } else {
        return new VarBool(lineNum, getDouble() > second.getDouble());
    }
}

Var* Var::operator >= (const Var& second) const {
    if (type == STRING_VAR || second.getType() == STRING_VAR) {
        return new VarBool(lineNum, getString().length() >= second.getString().length());
    } else {
        return new VarBool(lineNum, getDouble() >= second.getDouble());
    }
}

Var* Var::operator == (const Var& second) const {
    return new VarBool(lineNum, getString() == second.getString());
}

Var* Var::operator != (const Var& second) const {
    return new VarBool(lineNum, getString() != second.getString());
}

Var* Var::operator && (const Var& second) const {
    return new VarBool(lineNum, getBool() && second.getBool());
}

Var* Var::operator || (const Var& second) const {
    return new VarBool(lineNum, getBool() || second.getBool());
}

Var::VarType Var::getType() const {
    return type;
}

bool Var::getBool() const {
    throwExcConvert(getString(), "'bool'");
}

long long Var::getInteger() const {
    throwExcConvert(getString(), "'int'");
}

long double Var::getDouble() const {
    throwExcConvert(getString(), "'float'");
}
