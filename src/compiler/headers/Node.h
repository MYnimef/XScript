//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include <list>
#include "Token.h"

class Node final {
private:
    Token token;
    std::list<Node*> nodes;

public:
    Node(const Token&);
    ~Node();

    EType getType();
    std::string getValue();
    Token getToken();

    void addChildFront(Node *child);
    void addChildBack(Node *child);
    std::list<Node*> getChild();

    std::string printChild(int = 1);
};
