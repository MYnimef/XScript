#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Compiler.h"

int main() {
    Lexer lexer;
    lexer.scanFile("main.dsl");

    for (auto token: lexer.getTokens()) {
        if (token->getType() != SEMICOLON) {
            std::cout << token->toString() << std::endl;
        }
    }

    Parser parser;
    parser.toPostfix(lexer.getTokens());

    std::cout << std::endl << parser.getTree()->printChild();

    Compiler compiler;
    compiler.execute(parser.getTree());

    std::cout << std::endl;
    for (const auto& var: compiler.getIntegerVariables()) {
        std::cout << std::endl << var.first + " = " + std::to_string(var.second);
    }

    for (const auto& var: compiler.getDoubleVariables()) {
        std::cout << std::endl << var.first + " = " + std::to_string(var.second);
    }

    for (const auto& var: compiler.getStringVariables()) {
        std::cout << std::endl << var.first + " = " + var.second;
    }
    std::cout << std::endl;

    return 0;
}
