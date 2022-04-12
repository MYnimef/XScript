//
// Created by Ivan Markov on 11.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"
#include "Node.h"

class ExpBlock final: public Exp {
private:
    const std::string name;

public:
    explicit ExpBlock(const std::string& name);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
