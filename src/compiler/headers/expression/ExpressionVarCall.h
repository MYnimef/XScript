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

    void action(
            std::list<std::map<std::string, Variable*>*> variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
    ) const override;

    [[nodiscard]] std::string toString() const override;
};
