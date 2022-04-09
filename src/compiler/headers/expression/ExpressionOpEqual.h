//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionOpEqual final: public Expression {
public:
    explicit ExpressionOpEqual();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
