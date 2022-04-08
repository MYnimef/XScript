//
// Created by Ivan Markov on 07.03.2022.
//

#include "Node.h"

Node::Node(const Expression* expression):
expression(expression) {
}

Node::~Node() {
    delete expression;
    for (auto child: nodes) {
        delete child;
    }
}

ExpressionType Node::getType() {
    return expression->getType();
}

void Node::addChildFront(Node* child) {
    nodes.push_front(child);
}

void Node::addChildBack(Node* child) {
    nodes.push_back(child);
}

std::list<Node *> Node::getChild() {
    return nodes;
}

const Expression* Node::getToken() const {
    return expression;
}
