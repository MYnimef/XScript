//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpBlock.h"

ExpBlock::ExpBlock(const std::string& name):
name(name) {
    type = EXP_CODE_BLOCK;
}

void ExpBlock::action(const CompilerArgs &args) const {

}

std::string ExpBlock::toString() const {
    return name;
}
