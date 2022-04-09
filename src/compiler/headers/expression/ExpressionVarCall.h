//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"

class ExpressionVarCall final: public Expression {
private:
    std::string id;

    bool callVariableFrom(std::map<std::string, Variable*>* container,std::stack<Variable*>& stack) const;

public:
    explicit ExpressionVarCall(const std::string& value);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
