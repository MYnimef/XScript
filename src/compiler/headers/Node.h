//
// Created by Ivan Markov on 07.03.2022.
//

#pragma once

#include "Token.h"

class Node final {
private:
    Token token;
    Node* left;
    Node* right;

public:
    Node(const Token&);
    ~Node();

    Type getType();
    std::string getValue();

    void setLeft(Node*);
    const Node& getLeft();

    void setRight(Node*);
    const Node& getRight();
};
