//
// Created by Ivan Markov on 08.04.2022.
//

#pragma once

#include "Exp.h"
#include "Node.h"

class ExpBlockIf final: public Exp {
private:
    const std::list<Node*>* blockConditions;
    const std::list<Node*>* blockExecutes;
    const std::list<std::map<std::string, Node*>*>* functions;

public:
    explicit ExpBlockIf(
            const int& lineNum,
            const std::list<Node*>* blockConditions,
            const std::list<Node*>* blockExecutes,
            const std::list<std::map<std::string, Node*>*>* functions
            );
    ~ExpBlockIf() override;

    void action(const InterpreterArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
