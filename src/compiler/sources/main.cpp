#include <iostream>
#include "Lexer.h"

int main() {
#if (CMAKE_BUILD_TYPE == Debug)
    printf("RUNNING DEBUG BUILD\n");
#else
    printf("Running... this is a release build.\n");
#endif

    Lexer lexer;

    //lexer.scanFile("~/main.dsl");

    lexer.addToken("(");
    lexer.addToken("99");
    lexer.addToken("abc");
    lexer.addToken("\"\"");
    lexer.addToken("\"hi\"");
    lexer.addToken("\"hi99\"");

    for (auto token: lexer.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    return 0;
}
