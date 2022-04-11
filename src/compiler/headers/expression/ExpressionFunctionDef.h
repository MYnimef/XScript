//
// Created by Ivan Markov on 11.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"
#include "Node.h"

class ExpressionFunctionDef final: public Expression {
private:
    const std::string name;
    const std::list<Node*> arguments;
    const Node* body;

public:
    explicit ExpressionFunctionDef(const std::string& value, const std::list<Node*>& arguments, const Node* body);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
