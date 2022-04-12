//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Exc.h"

class ExcLexer final: public Exc {
public:
    explicit ExcLexer(const std::string& message, const int& lineNum);
};
