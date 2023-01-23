//
// Created by Ivan Markov on 09.04.2022.
//

#include "InterpreterArgs.h"

InterpreterArgs::InterpreterArgs(
        std::map<std::string, Node*>* functions,
        std::list<std::map<std::string, Var*>*>& variablesGlobal,
        std::map<std::string, Var*>* variables,
        std::stack<Var*>& stack
        ):
        functions(functions),
        variablesGlobal(variablesGlobal),
        stack(stack) {
    this->variables = variables;
}
