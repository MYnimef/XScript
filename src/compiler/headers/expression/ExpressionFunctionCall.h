//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"
#include "Node.h"

class ExpressionFunctionCall final: public Expression {
private:
    std::string name;
    std::list<Node*> arguments;

public:
    explicit ExpressionFunctionCall(const std::string& value);
    explicit ExpressionFunctionCall(const std::string& value, std::list<Node*> arguments);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
