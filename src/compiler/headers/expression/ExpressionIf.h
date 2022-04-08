//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Expression.h"
#include "Node.h"

class ExpressionIf final: public Expression {
private:
    const Node* block;

public:
    explicit ExpressionIf(const Node* value);

    void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
    ) const override;

    [[nodiscard]] std::string toString() const override;
};
