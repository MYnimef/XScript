#include <iostream>
#include "Lexer.h"

int main() {
    Lexer lexer;
    lexer.scanFile("main.dsl");

    for (auto token: lexer.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    return 0;
}
