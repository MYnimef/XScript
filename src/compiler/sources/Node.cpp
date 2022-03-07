//
// Created by Ivan Markov on 07.03.2022.
//

#include "Node.h"

Node::Node(const Token& token)
: token(token) {
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    delete right;
    delete left;
}

Type Node::getType() {
    return token.getType();
}

std::string Node::getValue() {
    return token.getValue();
}

void Node::setLeft(Node* node) {
    left = node;
}

const Node& Node::getLeft() {
    return *left;
}

void Node::setRight(Node* node) {
    right = node;
}

const Node& Node::getRight() {
    return *right;
}
