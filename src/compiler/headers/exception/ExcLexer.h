//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExcLexer final: public std::runtime_error {
public:
    explicit ExcLexer(const std::string& message);
};
