#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Compiler.h"

int main() {
    clock_t start = clock();

    Lexer lexer;
    lexer.scanFile("main.dsl");

    for (const auto& token: lexer.getTokens()) {
        if (token.getType() != SEMICOLON) {
            std::cout << token.toString() << std::endl;
        }
    }

    Parser parser("main");
    parser.addTokens(lexer.getTokens());

    Compiler compiler;
    compiler.execute(parser.getTree());

    std::cout << std::endl;
    for (const auto& var: compiler.getVariables()) {
        std::cout << std::endl << var.first + " = " + var.second.toString();
    }
    std::cout << std::endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    std::cout << std::endl << "Program compiled in " << elapsed << std::endl;

    return 0;
}
