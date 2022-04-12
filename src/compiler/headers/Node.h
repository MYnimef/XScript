//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include <list>
#include "Exp.h"

class Node final {
private:
    const Exp* expression;
    std::list<Node*> children;

public:
    explicit Node(const Exp*);
    Node(const Exp*, const std::list<Node*>&);
    ~Node();

    ExpressionType getType();
    [[nodiscard]] const Exp* getExpression() const;

    void addChildFront(Node *child);
    void addChildBack(Node *child);
    [[nodiscard]] std::list<Node*> getChildren() const;

    [[nodiscard]] std::string toString(int gen = 0) const;
};
