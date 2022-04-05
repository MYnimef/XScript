//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include <iostream>
#include "Parser.h"

Parser::Parser(const std::string& name) {
    tree = new Node(Token(ID, name));
}

Parser::~Parser() {

}

void Parser::addTokens(const std::list<Token*>& tokens) {
    std::list<Token*> tokensLine;

    int openedBrackets = 0;
    int openedBraces = 0;

    bool semicolon = false;
    bool op = false;

    for (const auto& token: tokens) {
        const auto type = token->getType();

        if (type == SEMICOLON) {
            if (openedBraces == 0) {
                if (openedBrackets == 0) {
                    semicolon = true;
                }
            } else {
                tokensLine.push_back(token);
            }
        } else {
            if ((type == ID || type == KEY_WORD) && !op) {
                if (semicolon) {
                    addTokensLine(tokensLine);
                    tokensLine.clear();
                }
            } else if (type == OPERATOR) {
                op = true;
            } else if (type == L_BRACKET) {
                openedBrackets++;
            } else if (type == R_BRACKET) {
                openedBrackets--;
            } else if (type == L_BRACE) {
                openedBraces++;
            } else if (type == R_BRACE) {
                openedBraces--;
            } else {
                op = false;
            }

            semicolon = false;
            tokensLine.push_back(token);
        }
    }

    addTokensLine(tokensLine);
    tokensLine.clear();
}

void Parser::addTokensLine(const std::list<Token*>& tokens) {
    std::cout << std::endl;
    for (auto i: tokens) {
        std::cout << i->getValue() << " ";
    }

    std::list<Token*> postfix;
    std::stack<Token*> operators;

    for (auto token: tokens) {
        switch (token->getType()) {
            case ID:
            case DOUBLE_DIGIT:
            case INT_DIGIT:
            case STRING:
            case KEY_WORD:
                postfix.push_back(token);
                break;
            case L_BRACKET:
                operators.push(token);
                break;
            case R_BRACKET:
                while (operators.top()->getType() != L_BRACKET) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
                break;
            case L_BRACE:
                break;
            case R_BRACE:
                break;
            case OPERATOR:
                while (
                        !operators.empty()
                        &&
                        operatorPriority(token->getValue()) <= operatorPriority(operators.top()->getValue())
                ) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
                break;
            case SEMICOLON:
                break;
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }
    tree->addChildBack(addNodeExpr(postfix));
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

Node* Parser::addNodeExpr(std::list<Token*>& postfix) {
    std::cout << std::endl;
    for (auto i: postfix) {
        std::cout << i->getValue() << " ";
    }

    std::stack<Node*> st;

    for (auto tk: postfix) {
        Node* node = new Node(*tk);
        if (node->getType() == OPERATOR) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        }
        st.push(node);
    }

    postfix.clear();
    Node* result = st.top();
    st.pop();

    return result;
}

Node *Parser::getTree() {
    return tree;
}
