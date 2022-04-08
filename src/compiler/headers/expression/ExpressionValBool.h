//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionValBool final: public Expression {
private:
    bool value;

public:
    explicit ExpressionValBool(const std::string& value);

    virtual void action(
            std::map<std::string, Variable *> &variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable *> &stack
    ) const;

    [[nodiscard]] std::string toString() const override;
};
