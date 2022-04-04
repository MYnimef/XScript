//
// Created by Ivan Markov on 06.03.2022.
//

#pragma once

#include <list>
#include "Token.h"
#include "Node.h"

class Parser final {
private:
    Node* tree;

    short operatorPriority(const std::string&);
    Node* addNodeExpr(std::list<Token*>&);

public:
    Parser();
    ~Parser();

    void toPostfix(const std::list<Token*>&);
    Node* getTree();
};