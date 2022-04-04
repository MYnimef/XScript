//
// Created by Ivan Markov on 08.03.2022.
//

#include "Compiler.h"

void Compiler::execute(Node* tree) {
    auto child = tree->getChild();

    if (child.empty()) {
        EType type = tree->getType();
        if (type == ID) {
            auto token = tree->getToken();
            if (checkVariable(token)) {
                return;
            }
        } else if (type == INT_DIGIT) {
            stack.push(Variable(std::stoi(tree->getValue())));
        } else if (type == DOUBLE_DIGIT) {
            stack.push(Variable(std::stod(tree->getValue())));
        } else if (type == STRING) {
            std::string value = tree->getValue();
            value = value.substr(1, value.size() - 2);
            stack.push(Variable(value));
        }
    } else if (child.size() == 2) {
        auto left = child.front();
        auto right = child.back();
        std::string op = tree->getValue();

        if (left->getType() == ID && op == "=") {
            execute(right);

            if (!stack.empty()) {
                variables.insert_or_assign(left->getValue(), stack.top());
            }
        } else {
            execute(left);
            execute(right);

            auto arg2 = stack.top();
            stack.pop();
            auto arg1 = stack.top();
            stack.pop();

            if (op == "+") {
                stack.push(arg1 + arg2);
            } else if (op == "-") {
                stack.push(arg1 - arg2);
            } else if (op == "*") {
                stack.push(arg1 * arg2);
            } else if (op == "/") {
                stack.push(arg1 / arg2);
            }
        }
    } else {
        for (auto node: tree->getChild()) {
            execute(node);
        }
    }
}

bool Compiler::checkVariable(const Token& token) {
    auto it = variables.find(token.getValue());
    if (it != variables.end()) {
        stack.push(it->second);
        return true;
    }
    return false;
}

const std::map<std::string, Variable> &Compiler::getVariables() const {
    return variables;
}
