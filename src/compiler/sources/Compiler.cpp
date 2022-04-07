//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

void Compiler::execute(Node* tree) {
    auto child = tree->getChild();

    for (auto node: tree->getChild()) {
        execute(node);
    }

    switch (tree->getType()) {
        case EXP_VAR_INITIALIZATION: {
            auto value = tree->getValue();
            stackVariablesId.push(tree->getValue());
            break;
        }
        case EXP_ID: {
            auto val = tree->getValue();
            auto it = variables.find(tree->getToken().getValue());
            if (it != variables.end()) {
                stack.push(it->second);
            } else {
                throw std::overflow_error("usage of undeclared var");
            }
            break;
        }
        case EXP_INTEGER: {
            stack.push(Variable(std::stoi(tree->getValue())));
            break;
        }
        case EXP_DOUBLE: {
            stack.push(Variable(std::stod(tree->getValue())));
            break;
        }
        case EXP_STRING: {
            std::string value = tree->getValue();
            value = value.substr(1, value.size() - 2);
            stack.push(Variable(value));
            break;
        }
        case EXP_OP_ASSIGNMENT: {
            variables.insert_or_assign(stackVariablesId.top(), stack.top());
            stackVariablesId.pop();
            break;
        }
        case EXP_OP_SUM: {
            auto arg2 = stack.top();
            stack.pop();
            auto arg1 = stack.top();
            stack.pop();
            stack.push(arg1 + arg2);
            break;
        }
        case EXP_OP_SUBTRACTION: {
            auto arg2 = stack.top();
            stack.pop();
            auto arg1 = stack.top();
            stack.pop();
            stack.push(arg1 - arg2);
            break;
        }
        case EXP_OP_MULTIPLICATION: {
            auto arg2 = stack.top();
            stack.pop();
            auto arg1 = stack.top();
            stack.pop();
            stack.push(arg1 * arg2);
            break;
        }
        case EXP_OP_DIVISION: {
            auto arg2 = stack.top();
            stack.pop();
            auto arg1 = stack.top();
            stack.pop();
            stack.push(arg1 / arg2);
            break;
        }
        case EXP_LOOP_WHILE: {
            break;
        }
        case EXP_LOOP_FOR: {
            break;
        }
        case EXP_FUNC: {
            break;
        }
        case EXP_FUNC_DEFINITION: {
            break;
        }
    }
}

bool Compiler::checkVariable(const Expression& exp) {
    auto it = variables.find(exp.getValue());
    if (it != variables.end()) {
        stack.push(it->second);
        return true;
    }
    return false;
}

const std::map<std::string, Variable> &Compiler::getVariables() const {
    return variables;
}
