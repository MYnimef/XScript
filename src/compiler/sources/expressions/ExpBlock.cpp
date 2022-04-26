//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpBlock.h"

ExpBlock::ExpBlock(const int& lineNum, const std::string& name):
Exp(EXP_CODE_BLOCK, lineNum),
name(name) {
    type = EXP_CODE_BLOCK;
}

void ExpBlock::action(const InterpreterArgs &args) const {

}

std::string ExpBlock::toString() const {
    return name;
}
