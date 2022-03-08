//
// Created by Ivan Markov on 08.03.2022.
//

#include <iostream>
#include "Compiler.h"

void Compiler::execute(Node* tree) {
    auto child = tree->getChild();

    if (child.empty()) {
        EType type = tree->getType();
        if (type == ID) {
            auto token = tree->getToken();
            if (checkVariable(integerVariables, integerStack, token)) {
                return;
            } else if (checkVariable(doubleVariables, doubleStack, token)) {
                return;
            } else if (checkVariable(stringVariables, stringStack, token)) {
                return;
            } else {

            }
        } else if (type == INT_DIGIT) {
            integerStack.push(std::stoi(tree->getValue()));
        } else if (type == DOUBLE_DIGIT) {
            doubleStack.push(std::stod(tree->getValue()));
        } else if (type == STRING) {
            std::string value = tree->getValue();
            value = value.substr(1, value.size() - 2);
            stringStack.push(value);
        }
    } else if (child.size() == 2) {
        auto left = child.front();
        auto right = child.back();

        execute(left);
        std::string op = tree->getValue();

        if (right->getType() == ID && op == "=") {
            if (!integerStack.empty()) {
                integerVariables.insert_or_assign(right->getValue(), integerStack.top());
                integerStack.pop();
            } else if (!doubleStack.empty()) {
                doubleVariables.insert_or_assign(right->getValue(), doubleStack.top());
                doubleStack.pop();
            } else if (!stringStack.empty()) {
                stringVariables.insert_or_assign(right->getValue(), stringStack.top());
                stringStack.pop();
            }
        } else {
            execute(right);
            if (op == "+") {
                if (integerStack.size() == 2) {
                    similarPlus(integerStack);
                } else if (doubleStack.size() == 2) {
                    similarPlus(doubleStack);
                } else if (stringStack.size() == 2) {
                    similarPlus(stringStack);
                }
            } else if (op == "-") {
                if (integerStack.size() == 2) {
                    similarMinus(integerStack);
                } else if (doubleStack.size() == 2) {
                    similarMinus(doubleStack);
                }
            } else if (op == "*") {
                if (integerStack.size() == 2) {
                    similarMux(integerStack);
                } else if (doubleStack.size() == 2) {
                    similarMux(doubleStack);
                }
            } else if (op == "/") {
                if (integerStack.size() == 2) {
                    similarDivide(integerStack);
                } else if (doubleStack.size() == 2) {
                    similarDivide(doubleStack);
                }
            }
        }
    } else {
        for (auto node: tree->getChild()) {
            execute(node);
        }
    }
}

template<class Type>
bool Compiler::checkVariable(std::map<std::string, Type>& variables, std::stack<Type>& values, const Token& token) {
    auto it = variables.find(token.getValue());
    if (it != variables.end()) {
        values.push(it->second);
        return true;
    }
    return false;
}

template<class Type>
void Compiler::similarPlus(std::stack<Type>& values) {
    Type arg1;
    Type arg2;
    similar(values, arg1, arg2);
    values.push(arg1 + arg2);
}

template<class Type>
void Compiler::similarMinus(std::stack<Type>& values) {
    Type arg1;
    Type arg2;
    similar(values, arg1, arg2);
    values.push(arg1 - arg2);
}

template<class Type>
void Compiler::similarMux(std::stack<Type>& values) {
    Type arg1;
    Type arg2;
    similar(values, arg1, arg2);
    values.push(arg1 * arg2);
}

template<class Type>
void Compiler::similarDivide(std::stack<Type>& values) {
    Type arg1;
    Type arg2;
    similar(values, arg1, arg2);
    double a1 = arg1;
    double a2 = arg2;
    doubleStack.push(a1 / a2);
}

template<class Type>
void Compiler::similar(std::stack<Type>& values, Type& arg1, Type& arg2) {
    arg2 = values.top();
    values.pop();
    arg1 = values.top();
    values.pop();
}

const std::map<std::string, int> &Compiler::getIntegerVariables() const {
    return integerVariables;
}

const std::map<std::string, double> &Compiler::getDoubleVariables() const {
    return doubleVariables;
}

const std::map<std::string, std::string> &Compiler::getStringVariables() const {
    return stringVariables;
}
