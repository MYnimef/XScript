//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include <list>
#include "Expression.h"

class Node final {
private:
    const Expression* expression;
    std::list<Node*> nodes;

public:
    Node(const Expression*);
    ~Node();

    ExpressionType getType();
    [[nodiscard]] const Expression* getToken() const;

    void addChildFront(Node *child);
    void addChildBack(Node *child);
    std::list<Node*> getChild();
};
