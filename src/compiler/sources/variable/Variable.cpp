//
// Created by Ivan Markov on 04.04.2022.
//

#include "Variable.h"
#include "VariableBool.h"

Variable::Variable() {

}

Variable::~Variable() {

}

Variable* Variable::operator < (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        return new VariableBool(getString().length() < second.getString().length());
    } else {
        return new VariableBool(getDouble() < second.getDouble());
    }
}

Variable* Variable::operator <= (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        return new VariableBool(getString().length() <= second.getString().length());
    } else {
        return new VariableBool(getDouble() <= second.getDouble());
    }
}

Variable* Variable::operator > (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        return new VariableBool(getString().length() > second.getString().length());
    } else {
        return new VariableBool(getDouble() > second.getDouble());
    }
}

Variable* Variable::operator >= (const Variable& second) const {
    if (second.getType() == STRING_VAR) {
        return new VariableBool(getString().length() >= second.getString().length());
    } else {
        return new VariableBool(getDouble() >= second.getDouble());
    }
}

Variable* Variable::operator == (const Variable& second) const {
    return new VariableBool(getString() == second.getString());
}

Variable* Variable::operator != (const Variable& second) const {
    return new VariableBool(getString() != second.getString());
}

Variable* Variable::operator && (const Variable& second) const {
    return new VariableBool(getBool() && second.getBool());
}

Variable* Variable::operator || (const Variable& second) const {
    return new VariableBool(getBool() || second.getBool());
}

Variable::VarType Variable::getType() const {
    return type;
}
