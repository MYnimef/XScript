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
    std::map<std::string, Node*>* functions;

public:
    explicit ExpBlockWhile(
            const Node* blockCondition,
            const Node* blockExecute,
            std::map<std::string, Node*>* functions
            );
    ~ExpBlockWhile() override;

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
