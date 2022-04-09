//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once

#include "Expression.h"

class ExpressionValInteger final: public Expression {
private:
    int value;

public:
    explicit ExpressionValInteger(int value);
    explicit ExpressionValInteger(const std::string& value);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
