//
// Created by Ivan Markov on 07.03.2022.
//

#include <iostream>
#include "Node.h"

Node::Node(const Token& token)
: token(token) {
}

Node::~Node() {
}

EType Node::getType() {
    return token.getType();
}

std::string Node::getValue() {
    return token.getValue();
}

void Node::addChildFront(Node* child) {
    nodes.push_front(child);
}

void Node::addChildBack(Node* child) {
    nodes.push_back(child);
}

std::string Node::printChild(int gen) {
    std::string tab;
    for (int i = 0; i < gen; i++) {
        tab += "    ";
    }

    std::string res = getValue();
    for (auto node: nodes) {
        res += "\n" + tab + node->printChild(gen + 1);
    }

    return res;
}

std::list<Node *> Node::getChild() {
    return nodes;
}

Token Node::getToken() {
    return token;
}
