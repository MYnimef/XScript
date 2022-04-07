#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Compiler.h"

int main() {
    Lexer lexer;
    lexer.scanFile("main.dsl");

    for (auto token: lexer.getTokens()) {
        if (token.getType() != SEMICOLON) {
            std::cout << token.toString() << std::endl;
        }
    }

    Parser parser("main");
    parser.addTokens(lexer.getTokens());

    std::cout << std::endl << parser.getTree()->printChild() << std::endl;

    Compiler compiler;
    compiler.execute(parser.getTree());

    std::cout << std::endl;
    for (const auto& var: compiler.getVariables()) {
        std::cout << std::endl << var.first + " = " + var.second.toString();
    }
    std::cout << std::endl;

    return 0;
}
