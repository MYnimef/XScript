//
// Created by Ivan Markov on 05.03.2022.
//

#include <fstream>
#include "Lexer.h"

using namespace std;

Lexer::Lexer(): lexems({
    { ID, regex( "[a-z][a-zA-Z0-9]*" ) },  // lower-case style of definition
    { DOUBLE_DIGIT, regex( "(0|([1-9][0-9]*))\\.*[0-9]*" ) }, // can be 0 but can't start with 0
    { INT_DIGIT, regex( "0|([1-9][0-9]*)" ) }, // can be 0 but can't start with 0
    { STRING, regex( R"("[0-9a-zA-Z\*\\/&\s]*")" ) },
    { IF_KW, regex( "if" ) },
    { ELSE_KW, regex( "else" ) },
    { FUNC_KW, regex( "func" ) },
    { L_BRACKET, regex( R"(\()" ) },       // can be only (
    { R_BRACKET, regex( R"(\))" ) },       // can be only )
    { L_BRACE, regex( R"(\{)" ) },         // can be only {
    { R_BRACE, regex( R"(\})" ) },         // can be only }
    { ASSIGN_OP, regex( "=" ) },
    { PLUS_OP, regex( "\\+" ) },
    { MINUS_OP, regex( "-" ) },
    { MULTIPLY_OP, regex( "\\*" ) },
    { DIVIDE_OP, regex( "/" ) },
}) {
    tokens = list<Token*>();
}

Lexer::~Lexer() {
    for (auto token: tokens) {
        delete token;
    }
}

void Lexer::scanFile(const string& filename) {
    ifstream file("../src/" + filename);

    if (!file.is_open()) {
        throw invalid_argument( "can't open file " + filename );
    }

    string line;
    for (int i = 0; getline(file, line); i++) {
        if (!line.empty()) {
            string oldStr;

            for (int startIndex = 0, endIndex = 1; endIndex <= line.size(); endIndex++) {
                if (startIndex < endIndex) {
                    string newStr = line.substr(startIndex, endIndex - startIndex);

                    if (newStr == " ") {
                        startIndex++;
                        continue;
                    } else if (!checkToken(newStr)) {
                        addToken(oldStr.empty() ? newStr : oldStr, i);
                        endIndex--;
                        startIndex = endIndex;
                    } else if (endIndex == line.size()) {
                        addToken(newStr, i);
                    }

                    oldStr = newStr;
                }
            }
        }
    }
}

bool Lexer::checkToken(const string& input) {
    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            return true;
        }
    }
    return false;
}

void Lexer::addToken(const string& input, const int& lineNum) {
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
        throw invalid_argument("wrong syntax at line " + to_string(lineNum + 1) + ": " + input);
    }
}

list<Token *> Lexer::getTokens() {
    return tokens;
}
