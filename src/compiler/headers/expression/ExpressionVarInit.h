//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"

class ExpressionVarInit final: public Expression {
private:
    std::string id;

public:
    explicit ExpressionVarInit(const std::string& value);

    void action(
            std::map<std::string, Variable>& variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable>& stack
    ) const override;
};
