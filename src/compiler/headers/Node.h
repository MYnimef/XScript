//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include <list>
#include "Expression.h"

class Node final {
private:
    Expression token;
    std::list<Node*> nodes;

public:
    Node(const Expression&);
    ~Node();

    ExpressionType getType();
    std::string getValue();
    Expression getToken();

    void addChildFront(Node *child);
    void addChildBack(Node *child);
    std::list<Node*> getChild();

    std::string printChild(int = 1);
};
