//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Expression.h"
#include "Node.h"

class ExpressionWhile final: public Expression {
private:
    const Node* blockCondition;
    const Node* blockExecute;

public:
    explicit ExpressionWhile(const Node* blockCondition, const Node* blockExecute);
    ~ExpressionWhile() override;

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
