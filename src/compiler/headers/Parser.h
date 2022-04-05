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
    explicit Parser(const std::string& name);
    ~Parser();

    void addTokens(const std::list<Token*>&);
    void addTokensLine(const std::list<Token*>&);
    Node* getTree();
};