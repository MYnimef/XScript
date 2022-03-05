//
// Created by Ivan Markov on 05.03.2022.
//

#include "Lexer.h"

const std::map<Type, std::regex> Lexer::lexems = {
        { VAR, std::regex( "[a-z][a-zA-Z0-9]*" ) },  // lower-case style of definition
        { DIGIT, std::regex( "0|([1-9][0-9]*)" ) }, // can be 0 but can't start with 0
        { STRING, std::regex( R"("[0-9a-zA-Z\*\\/&\s]*")" ) },
        { FUNC, std::regex( "[a-z][a-zA-Z]*" ) },    // lower-case style of definition, only literals
        { IF_KW, std::regex( "if" ) },
        { ELSE_KW, std::regex( "else" ) },
        { L_BRACKET, std::regex( R"(\()" ) },       // can be only (
        { R_BRACKET, std::regex( R"(\))" ) },       // can be only )
        { L_BRACE, std::regex( R"(\{)" ) },         // can be only {
        { R_BRACE, std::regex( R"(\})" ) },         // can be only }
        { ASSIGN_OP, std::regex( "=" ) },
};

Lexer::Lexer() {
    tokens = std::list<Token*>();
}

Lexer::~Lexer() {
    for (auto token: tokens) {
        delete token;
    }
}

void Lexer::addToken(const std::string& input) {
    Token* token = nullptr;
    for (const auto& lexem: lexems) {
        if (std::regex_match(input, lexem.second)) {
            if (token) {
                delete token;
            }
            token = new Token(lexem.first, input);
        }
    }
    if (token) {
        tokens.push_back(token);
    } else {
        throw std::invalid_argument( "received negative value" );
    }
}

std::list<Token *> Lexer::getTokens() {
    return tokens;
}
