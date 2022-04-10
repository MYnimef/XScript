//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExceptionParser final: public std::runtime_error {
public:
    explicit ExceptionParser(const std::string& message);
};
