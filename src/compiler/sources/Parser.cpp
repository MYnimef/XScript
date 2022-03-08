//
// Created by Ivan Markov on 06.03.2022.
//

#include <stack>
#include "Parser.h"

Parser::Parser() {
    tree = new Node(Token(ID, ""));
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
                if (semicolon) {
                    semicolon = false;
                    tree->addChildBack(addNode(postfix));
                }

                op = false;
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
    tree->addChildBack(addNode(postfix));
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

Node* Parser::addNode(std::list<Token*>& postfix) {
    Node* node = new Node(*postfix.back());
    postfix.pop_back();

    node->addChildFront(new Node(*postfix.front()));
    postfix.pop_front();

    if (postfix.size() == 1) {
        node->addChildFront(new Node(*postfix.front()));
        postfix.pop_front();
    } else if (!postfix.empty()) {
        node->addChildFront(addNodeExpr(postfix));
    }

    return node;
}

Node* Parser::addNodeExpr(std::list<Token*>& postfix) {
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
