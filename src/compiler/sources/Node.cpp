//
// Created by Ivan Markov on 07.03.2022.
//

#include "Node.h"

Node::Node(const Exp* expression):
expression(expression) {}

Node::Node(const Exp* expression, const std::list<Node*>& children):
expression(expression),
children(children) {}

Node::~Node() {
    delete expression;
    for (auto child: children) {
        delete child;
    }
}

ExpressionType Node::getType() {
    return expression->getType();
}

void Node::addChildFront(Node* child) {
    children.push_front(child);
}

void Node::addChildBack(Node* child) {
    children.push_back(child);
}

std::list<Node *> Node::getChildren() const {
    return children;
}

const Exp* Node::getExpression() const {
    return expression;
}

std::string Node::toString(int gen) const {
    std::string tab;
    for (int i = 0; i <= gen; i++) {
        tab += "    ";
    }

    std::string res = expression->toString();
    for (auto node: children) {
        res += "\n" + tab + node->toString(gen + 1);
    }

    return res;
}
