//
// Created by Ivan Markov on 06.03.2022.
//

#pragma once

#include <list>
#include "Token.h"

class Parser final {
private:
    int operatorPriority(char);

public:
    Parser();
    ~Parser();

    void toPostfix(const std::list<Token*>&);
};