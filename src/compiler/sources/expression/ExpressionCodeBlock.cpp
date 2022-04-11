//
// Created by Ivan Markov on 11.04.2022.
//

#include "ExpressionCodeBlock.h"

ExpressionCodeBlock::ExpressionCodeBlock(const std::string& name):
name(name) {
    type = EXP_CODE_BLOCK;
}

void ExpressionCodeBlock::action(const CompilerArgs &args) const {

}

std::string ExpressionCodeBlock::toString() const {
    return name;
}
