//
// Created by Ivan Markov on 11.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"
#include "Node.h"

class ExpressionCodeBlock final: public Expression {
private:
    const std::string name;

public:
    explicit ExpressionCodeBlock(const std::string& name);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
