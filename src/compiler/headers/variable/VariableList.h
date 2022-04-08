//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Variable.h"

class VariableList final: public Variable {
private:
    std::list<Variable*> value;

public:
    explicit VariableList(std::list<Variable*> value);

    Variable* operator + (const Variable&) override;
    Variable* operator - (const Variable&) override;
    Variable* operator * (const Variable&) override;
    Variable* operator / (const Variable&) override;

    [[nodiscard]] bool getBool() const override;
    [[nodiscard]] int getInteger() const override;
    [[nodiscard]] double getDouble() const override;
    [[nodiscard]] std::string getString() const override;
    [[nodiscard]] virtual std::list<Variable*> getList() const override;
};
