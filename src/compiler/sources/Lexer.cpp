//
// Created by Ivan Markov on 05.03.2022.
//

#include "Lexer.h"

using namespace std;

Lexer::Lexer(): lexems({
    { VAR, regex( "[a-z][a-zA-Z0-9]*" ) },  // lower-case style of definition
    { DIGIT, regex( "0|([1-9][0-9]*)" ) }, // can be 0 but can't start with 0
    { STRING, regex( R"("[0-9a-zA-Z\*\\/&\s]*")" ) },
    { FUNC, regex( "[a-z][a-zA-Z]*" ) },    // lower-case style of definition, only literals
    { IF_KW, regex( "if" ) },
    { ELSE_KW, regex( "else" ) },
    { L_BRACKET, regex( R"(\()" ) },       // can be only (
    { R_BRACKET, regex( R"(\))" ) },       // can be only )
    { L_BRACE, regex( R"(\{)" ) },         // can be only {
    { R_BRACE, regex( R"(\})" ) },         // can be only }
    { ASSIGN_OP, regex( "=" ) },
}) {
    tokens = list<Token*>();
}

Lexer::~Lexer() {
    for (auto token: tokens) {
        delete token;
    }
}

void Lexer::addToken(const string& input) {
    Token* token = nullptr;
    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            if (token) {
                delete token;
            }
            token = new Token(lexem.first, input);
        }
    }
    if (token) {
        tokens.push_back(token);
    } else {
        throw invalid_argument( "wrong syntax" );
    }
}

list<Token *> Lexer::getTokens() {
    return tokens;
}
