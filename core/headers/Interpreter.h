//
// Created by Ivan Markov on 08.03.2022.
//

#pragma once

#include <list>
#include <map>
#include <stack>
#include "Node.h"
#include "Var.h"

class Interpreter final {
private:
    std::map<std::string, Node*>* functions;

    std::list<std::map<std::string, Var*>*> variablesGlobal;
    std::map<std::string, Var*>* variables;

    std::stack<Var*> stack;

    void cleanStack();

public:
    explicit Interpreter(std::map<std::string, Node*>* functions);
    explicit Interpreter(
            std::map<std::string, Node*>* functions,
            std::map<std::string, Var*>* variables
    );
    explicit Interpreter(
            std::map<std::string, Node*>* functions,
            const std::list<std::map<std::string, Var*>*>& variablesGlobal
            );

    ~Interpreter();

    void execute(const Node*);
    void executeChild(const Node*);

    [[nodiscard]] const std::map<std::string, Var*>* getVariables() const;
    std::stack<Var*>& getStack();
};