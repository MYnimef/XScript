//
// Created by Ivan Markov on 09.04.2022.
//

#include "CompilerArgs.h"

CompilerArgs::CompilerArgs(
        std::list<std::map<std::string, Node*>*>& functionsGlobal,
        std::map<std::string, Node*>* functions,
        std::list<std::map<std::string, Variable*>*>& variablesGlobal,
        std::map<std::string, Variable *>* variables,
        std::stack<std::string>& stackVariablesId,
        std::stack<Variable *>& stack
        ):
        functionsGlobal(functionsGlobal),
        functions(functions),
        variablesGlobal(variablesGlobal),
        stackVariablesId(stackVariablesId),
        stack(stack) {
    this->variables = variables;
}
