//
// Created by Ivan Markov on 10.04.2022.
//

#pragma once

#include "Exp.h"
#include "Node.h"

class ExpBlockWhile final: public Exp {
private:
    const Node* blockCondition;
    const Node* blockExecute;

public:
    explicit ExpBlockWhile(
            const int& lineNum,
            const Node* blockCondition,
            const Node* blockExecute
            );
    ~ExpBlockWhile() override;

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
