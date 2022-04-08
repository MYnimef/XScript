//
// Created by Ivan Markov on 04.04.2022.
//

#pragma once

#include <string>

class Variable {
public:
    explicit Variable();

    virtual Variable* operator + (const Variable&) = 0;
    virtual Variable* operator - (const Variable&) = 0;
    virtual Variable* operator * (const Variable&) = 0;
    virtual Variable* operator / (const Variable&) = 0;

    [[nodiscard]] virtual int getInteger() const = 0;
    [[nodiscard]] virtual double getDouble() const = 0;
    [[nodiscard]] virtual std::string getString() const = 0;

    enum VarType {
        INTEGER_VAR,
        DOUBLE_VAR,
        STRING_VAR
    };

    [[nodiscard]] VarType getType() const;

protected:
    VarType type;
};
