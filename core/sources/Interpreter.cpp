//
// Created by Ivan Markov on 08.03.2022.
//

#include <FuncToBool.h>
#include <FuncToInteger.h>
#include <FuncToDouble.h>
#include <FuncToString.h>
#include <FuncToList.h>
#include <FuncSleep.h>
#include <FuncSin.h>
#include <FuncCos.h>
#include "Interpreter.h"

Interpreter::Interpreter(std::map<std::string, Node*>* functions):
functions({ new std::map<std::string, Node*>{
                  { "bool1",     new Node( new FuncToBool       () ) },
                  { "int1",      new Node( new FuncToInteger    () ) },
                  { "float1",    new Node( new FuncToDouble     () ) },
                  { "string1",   new Node( new FuncToString     () ) },
                  { "list1",     new Node( new FuncToList       () ) },
                  { "sleep1",    new Node( new FuncSleep        () ) },
                  { "sin1",      new Node( new FuncSin          () ) },
                  { "cos1",      new Node( new FuncCos          () ) },
          }}) {
    this->functions.push_back(functions);
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
