//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Expression.h"
#include "Node.h"

class ExpressionIf final: public Expression {
private:
    const Node* blockCondition;
    const Node* blockExecute;

public:
    explicit ExpressionIf(const Node* blockCondition, const Node* blockExecute);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
