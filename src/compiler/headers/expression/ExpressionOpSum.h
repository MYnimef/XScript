//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpSum final: public Expression {
public:
    explicit ExpressionOpSum();

    void action(
            std::map<std::string, Variable *> &variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable *> &stack
    ) const override;
};
