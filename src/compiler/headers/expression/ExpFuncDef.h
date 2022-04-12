//
// Created by Ivan Markov on 11.04.2022.
//

#pragma once


#include <string>
#include "Exp.h"
#include "Node.h"

class ExpFuncDef final: public Exp {
private:
    const std::string name;
    const Node* body;
    std::map<std::string, Node*>* functions;

public:
    explicit ExpFuncDef(
            const std::string& value,
            const Node* body,
            std::map<std::string,Node*>* functions
            );

    ~ExpFuncDef();

    void action(const CompilerArgs& args) const override;

    [[nodiscard]] std::string toString() const override;
};
