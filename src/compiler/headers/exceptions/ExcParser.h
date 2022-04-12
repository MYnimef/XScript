//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Exc.h"

class ExcParser final: public Exc {
public:
    explicit ExcParser(const std::string& message, const int& lineNum);
};
