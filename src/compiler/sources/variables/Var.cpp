//
// Created by Ivan Markov on 04.04.2022.
//

#include "Var.h"
#include "VarBool.h"

Var::Var() {

}

Var::~Var() {

}

Var* Var::operator ! () const {
    return new VarBool(!getBool());
}

Var* Var::operator < (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(getString().length() < second.getString().length());
    } else {
        return new VarBool(getDouble() < second.getDouble());
    }
}

Var* Var::operator <= (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(getString().length() <= second.getString().length());
    } else {
        return new VarBool(getDouble() <= second.getDouble());
    }
}

Var* Var::operator > (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(getString().length() > second.getString().length());
    } else {
        return new VarBool(getDouble() > second.getDouble());
    }
}

Var* Var::operator >= (const Var& second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool(getString().length() >= second.getString().length());
    } else {
        return new VarBool(getDouble() >= second.getDouble());
    }
}

Var* Var::operator == (const Var& second) const {
    return new VarBool(getString() == second.getString());
}

Var* Var::operator != (const Var& second) const {
    return new VarBool(getString() != second.getString());
}

Var* Var::operator && (const Var& second) const {
    return new VarBool(getBool() && second.getBool());
}

Var* Var::operator || (const Var& second) const {
    return new VarBool(getBool() || second.getBool());
}

Var::VarType Var::getType() const {
    return type;
}
