//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once

#include "Exc.h"

class ExcVar final: public Exc {
public:
    explicit ExcVar(const std::string& message, const int& lineNum);
};
