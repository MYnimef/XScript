//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExcLexer.h"

ExcLexer::ExcLexer(const std::string &message) : runtime_error(
        "DSL Lexer Exception :: " + message) {

}
