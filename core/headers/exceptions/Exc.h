//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class Exc: public std::runtime_error {
public:
    explicit Exc(const std::string& type, const std::string& message, const int& lineNum);
};
