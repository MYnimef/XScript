//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include <iostream>
#include "Parser.h"

Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::toPostfix(const std::list<Token*>& tokens) {
    std::list<Token*> postfix;
    std::stack<Token*> operators;

    bool op = false;
    bool semicolon = false;
    for (auto token: tokens) {
        switch (token->getType()) {
            case ID:
            case DOUBLE_DIGIT:
            case INT_DIGIT:
            case STRING:
            case KEY_WORD: {
                op = false;
                semicolon = false;
                postfix.push_back(token);
                break;
            }
            case L_BRACKET: {
                operators.push(token);
                break;
            }
            case R_BRACKET: {
                while (operators.top()->getType() != L_BRACKET) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
                break;
            }
            case L_BRACE: {
                operators.push(token);
                op = false;
                semicolon = false;
                postfix.push_back(token);
                break;
            }
            case R_BRACE: {
                while (operators.top()->getType() != L_BRACE) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
                op = false;
                semicolon = false;
                postfix.push_back(token);
                break;
            }
            case OPERATOR: {
                if (semicolon) {
                    operators.push(postfix.back());
                    postfix.pop_back();
                    semicolon = false;
                }

                op = true;
                while (!operators.empty() &&
                operatorPriority(token->getValue()) <= operatorPriority(operators.top()->getValue())) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
                break;
            }
            case SEMICOLON: {
                if (!op) {
                    while (!operators.empty()) {
                        EType type = operators.top()->getType();
                        if (type != L_BRACE && type != L_BRACKET) {
                            postfix.push_back(operators.top());
                            operators.pop();
                        } else {
                            break;
                        }
                    }
                    semicolon = true;
                }
                break;
            }
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    std::cout << std::endl;
    for (auto token: postfix) {
        std::cout << token->getValue() << " ";
    }
}

short Parser::operatorPriority(const std::string& op) {
    if (op == "*" || op == "/") {
        return 4;
    } else if (op == "+" || op == "-") {
        return 3;
    } else if (op == "=" || op == "==") {
        return 2;
    } else if (op == "&&") {
        return 1;
    } else if (op == "||") {
        return 0;
    } else {
        return -1;
    }
}
