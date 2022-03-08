#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main() {
    Lexer lexer;
    lexer.scanFile("main.dsl");

    for (auto token: lexer.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    Parser parser;
    parser.toPostfix(lexer.getTokens());

    return 0;
}
