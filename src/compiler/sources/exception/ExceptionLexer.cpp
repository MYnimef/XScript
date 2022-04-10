//
// Created by Ivan Markov on 10.04.2022.
//

#include "ExceptionLexer.h"

ExceptionLexer::ExceptionLexer(const std::string &message) : runtime_error(
        "DSL Lexer Exception :: " + message) {

}
