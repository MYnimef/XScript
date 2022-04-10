//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpDiv final: public Expression {
public:
    explicit ExpressionOpDiv();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
