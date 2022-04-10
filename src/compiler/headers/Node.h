//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include <list>
#include "Expression.h"

class Node final {
private:
    const Expression* expression;
    std::list<Node*> children;

public:
    Node(const std::string& value);
    explicit Node(const Expression*);
    ~Node();

    ExpressionType getType();
    [[nodiscard]] const Expression* getExpression() const;

    void addChildFront(Node *child);
    void addChildBack(Node *child);
    [[nodiscard]] std::list<Node*> getChildren() const;

    [[nodiscard]] std::string toString(int gen = 0) const;
};
