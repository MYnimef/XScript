//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpSmallerOrEqual final: public Expression {
public:
    explicit ExpressionOpSmallerOrEqual();

    void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
    ) const override;

    [[nodiscard]] std::string toString() const override;
};
