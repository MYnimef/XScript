//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExcVar final: public std::runtime_error {
public:
    explicit ExcVar(const std::string& message);
};
