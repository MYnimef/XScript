//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>

enum VarType {
    INTEGER_VAR,
    DOUBLE_VAR,
    STRING_VAR
};

class Variable final {

private:
    VarType type;
    int intVal;
    double doubleVal;
    std::string stringVal;

public:
    explicit Variable(int);
    explicit Variable(double);
    explicit Variable(std::string);
    ~Variable();

    Variable operator + (const Variable&);
    Variable operator - (const Variable&);
    Variable operator * (const Variable&);
    Variable operator / (const Variable&);

    [[nodiscard]] std::string toString() const;
};
