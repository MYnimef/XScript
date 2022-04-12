//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExcParser final: public std::runtime_error {
public:
    explicit ExcParser(const std::string& message);
};
