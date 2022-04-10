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

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
