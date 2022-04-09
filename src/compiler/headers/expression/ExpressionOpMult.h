//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpMult final: public Expression {
public:
    explicit ExpressionOpMult();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
