//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"
#include "Node.h"

class ExpressionFunctionCall final: public Expression {
private:
    const std::string name;
    const std::list<Node*> arguments;

    void executeFunction(Node* func, const CompilerArgs& args) const;

public:
    explicit ExpressionFunctionCall(const std::string& value, const std::list<Node*>& arguments);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
