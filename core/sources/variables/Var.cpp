//
// Created by Ivan Markov on 04.04.2022.
//

#include "Var.h"
#include "VarBool.h"
#include "ExcVar.h"


Var::Var(const int& lineNum, const VarType& type):
lineNum(lineNum),
type(type) {}

Var::~Var() = default;

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
    return new VarBool(lineNum, !bool(*this));
}

Var* Var::operator < (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this < (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this < (long double) second);
    }
}

Var* Var::operator <= (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this <= (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this <= (long double) second);
    }
}

Var* Var::operator > (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this > (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this > (long double) second);
    }
}

Var* Var::operator >= (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this >= (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this >= (long double) second);
    }
}

Var* Var::operator == (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this == (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this == (long double) second);
    }
}

Var* Var::operator != (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(lineNum, (std::string) *this != (std::string) second);
    } else {
        return new VarBool(lineNum, (long double) *this != (long double) second);
    }
}

Var* Var::operator && (const Var& second) const {
    return new VarBool(lineNum, (bool) *this && (bool) second);
}

Var* Var::operator || (const Var& second) const {
    return new VarBool(lineNum, (bool) *this || (bool) second);
}

Var::VarType Var::getType() const {
    return type;
}

Var::operator bool() const {
    throwExcConvert(std::string(*this), "'bool'");
}

Var::operator long long() const {
    throwExcConvert(std::string(*this), "'int'");
}

Var::operator long double() const {
    throwExcConvert(std::string(*this), "'float'");
}

Var::operator std::list<Var*>() const {
    return { copy(lineNum) };
}
