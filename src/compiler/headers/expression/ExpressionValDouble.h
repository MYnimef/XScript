//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionValDouble final: public Expression {
private:
    double value;

public:
    explicit ExpressionValDouble(const std::string& value);

    virtual void action(
            std::map<std::string, Variable>& variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable>& stack
    ) const;
};
