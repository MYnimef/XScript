//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Exp.h"

class ExpValBool final: public Exp {
private:
    const bool value;

public:
    explicit ExpValBool(const int& lineNum, const std::string& value);

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
