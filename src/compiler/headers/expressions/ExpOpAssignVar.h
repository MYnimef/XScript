//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"

class ExpOpAssignVar final: public Exp {
private:
    std::string id;

public:
    explicit ExpOpAssignVar(const int& lineNum, const std::string& value);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
