//
// Created by Ivan Markov on 08.03.2022.
//

#pragma once

#include <list>
#include <map>
#include <stack>
#include "Node.h"
#include "Var.h"

class Compiler final {
private:
    std::list<std::map<std::string, Node*>*> functions;

    std::list<std::map<std::string, Var*>*> variablesGlobal;
    std::map<std::string, Var*>* variables;

    std::stack<Var*> stack;

public:
    explicit Compiler(std::map<std::string, Node*>* functions);
    explicit Compiler(
            const std::list<std::map<std::string, Node*>*>& functions,
            const std::list<std::map<std::string, Var*>*>& variablesGlobal
            );

    ~Compiler();

    void execute(const Node*);

    [[nodiscard]] const std::map<std::string, Var*>* getVariables() const;
    std::stack<Var*>& getStack();
};