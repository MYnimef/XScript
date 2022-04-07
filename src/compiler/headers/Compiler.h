//
// Created by Ivan Markov on 08.03.2022.
//

#pragma once

#include <map>
#include <stack>
#include "Node.h"
#include "Variable.h"

class Compiler final {
private:
    std::map<std::string, Variable> constants;
    std::map<std::string, Variable> variables;

    std::stack<std::string> stackConstantsId;
    std::stack<std::string> stackVariablesId;

    std::stack<Variable> stack;

    bool checkVariable(const Expression&);

public:
    void execute(Node*);

    [[nodiscard]] const std::map<std::string, Variable>& getVariables() const;
};