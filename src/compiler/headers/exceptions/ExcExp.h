//
// Created by Ivan Markov on 12.04.2022.
//

#pragma once

#include <stdexcept>
#include <string>

class ExcExp final: public std::runtime_error {
public:
    explicit ExcExp(const std::string& message);
};
