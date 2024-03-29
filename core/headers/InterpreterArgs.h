//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include <list>
#include <map>
#include <stack>
#include "Var.h"

class Node;

struct InterpreterArgs {
    std::map<std::string, Node*>* functions;

    std::list<std::map<std::string, Var*>*>& variablesGlobal;
    std::map<std::string, Var*>* variables;

    std::stack<Var*>& stack;

    InterpreterArgs(
            std::map<std::string, Node*>* functions,
            std::list<std::map<std::string, Var*>*>& variablesGlobal,
            std::map<std::string, Var*>* variables,
            std::stack<Var*>& stack
    );
};
