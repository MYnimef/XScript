//
// Created by Ivan Markov on 08.03.2022.
//

#pragma once

#include <list>
#include <map>
#include <stack>
#include "Node.h"
#include "Variable.h"

class Compiler final {
private:
    std::list<std::map<std::string, Variable*>*> variablesGlobal;
    std::map<std::string, Variable*>* variables;

    std::stack<std::string> stackVariablesId;
    std::stack<Variable*> stack;

public:
    Compiler();
    explicit Compiler(const std::list<std::map<std::string, Variable*>*>& variablesGlobal);

    ~Compiler();

    void execute(const Node*);

    [[nodiscard]] const std::map<std::string, Variable*>* getVariables() const;
};