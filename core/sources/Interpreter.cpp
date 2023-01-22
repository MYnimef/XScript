//
// Created by Ivan Markov on 08.03.2022.
//

#include "Interpreter.h"

Interpreter::Interpreter(std::map<std::string, Node*>* functions) {
    this->functions.push_front(functions);
    variables = new std::map<std::string, Var*>();
}

Interpreter::Interpreter(const std::list<std::map<std::string, Node*>*>& functions):
functions(functions) {
    variables = new std::map<std::string, Var*>();
}

Interpreter::Interpreter(
        const std::list<std::map<std::string, Node*>*>& functions,
        const std::list<std::map<std::string, Var*>*>& variablesGlobal
):
functions(functions),
variablesGlobal(variablesGlobal) {
    variables = new std::map<std::string, Var*>();
}

Interpreter::~Interpreter() {
    for (const auto& var: *variables) {
        delete var.second;
    }
    delete variables;
    cleanStack();
}

void Interpreter::execute(const Node* tree) {
    for (auto node: tree->getChildren()) {
        executeChild(node);
        cleanStack();
    }

    tree->getExpression()->action(InterpreterArgs(functions, variablesGlobal, variables, stack));
}

void Interpreter::executeChild(const Node* tree) {
    for (auto node: tree->getChildren()) {
        executeChild(node);
    }

    tree->getExpression()->action(InterpreterArgs(functions, variablesGlobal, variables, stack));
}

void Interpreter::cleanStack() {
    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

const std::map<std::string, Var*>* Interpreter::getVariables() const {
    return variables;
}

std::stack<Var*>& Interpreter::getStack() {
    return stack;
}
