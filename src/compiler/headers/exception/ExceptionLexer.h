//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExceptionLexer final: public std::runtime_error {
public:
    explicit ExceptionLexer(const std::string& message);
};
