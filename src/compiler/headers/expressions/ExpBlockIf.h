//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Exp.h"
#include "Node.h"

class ExpBlockIf final: public Exp {
private:
    const Node* blockCondition;
    const Node* blockExecute;
    std::map<std::string, Node*>* functions;

public:
    explicit ExpBlockIf(
            const int& lineNum,
            const Node* blockCondition,
            const Node* blockExecute,
            std::map<std::string, Node*>* functions
            );
    ~ExpBlockIf() override;

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
