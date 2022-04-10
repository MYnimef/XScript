//
// Created by Ivan Markov on 07.04.2022.
//

#pragma once


#include <string>
#include "Expression.h"

class ExpressionValString final: public Expression {
private:
    std::string value;

public:
    explicit ExpressionValString(const std::string& value);

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
