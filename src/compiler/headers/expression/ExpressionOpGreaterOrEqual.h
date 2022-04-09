//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpGreaterOrEqual final: public Expression {
public:
    explicit ExpressionOpGreaterOrEqual();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
