#include <iostream>
#include "Lexer.h"

int main() {
    Lexer lexer;

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
