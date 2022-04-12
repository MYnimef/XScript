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
    const Node* body;
    std::map<std::string, Node*>* functions;

public:
    explicit ExpressionFunctionDef(
            const std::string& value,
            const Node* body,
            std::map<std::string,Node*>* functions
            );

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
