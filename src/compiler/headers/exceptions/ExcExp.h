//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once

#include "Exc.h"

class ExcExp final: public Exc {
public:
    explicit ExcExp(const std::string& message, const int& lineNum);
};
