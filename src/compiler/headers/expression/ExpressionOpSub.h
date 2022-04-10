//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpSub final: public Expression {
public:
    explicit ExpressionOpSub();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
