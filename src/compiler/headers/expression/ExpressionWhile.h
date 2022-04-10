//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Expression.h"
#include "Node.h"

class ExpressionWhile final: public Expression {
private:
    const Node* block;

public:
    explicit ExpressionWhile(const Node* value);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
