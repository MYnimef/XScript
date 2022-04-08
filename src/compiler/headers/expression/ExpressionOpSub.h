//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpSub final: public Expression {
public:
    explicit ExpressionOpSub();

    void action(
            std::map<std::string, Variable *> &variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable *> &stack
    ) const override;

    [[nodiscard]] std::string toString() const override;
};
