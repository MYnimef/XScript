//
// Created by Ivan Markov on 09.04.2022.
//

#pragma once

#include <list>
#include <map>
#include <stack>
#include "Variable.h"

class Node;

struct CompilerArgs {
    std::list<std::map<std::string, Node*>*>& functionsGlobal;
    std::map<std::string, Node*>* functions;
    std::list<std::map<std::string, Variable*>*>& variablesGlobal;
    std::map<std::string, Variable*>* variables;
    std::stack<std::string>& stackVariablesId;
    std::stack<Variable*>& stack;

    CompilerArgs(
            std::list<std::map<std::string, Node*>*>& functionsGlobal,
            std::map<std::string, Node*>* functions,
            std::list<std::map<std::string, Variable*>*>& variablesGlobal,
            std::map<std::string, Variable*>* variables,
            std::stack<std::string>& stackVariablesId,
            std::stack<Variable*>& stack
    );
};
