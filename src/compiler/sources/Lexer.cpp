//
// Created by Ivan Markov on 05.03.2022.
//

#include <fstream>
#include "Lexer.h"

Lexer::Lexer(): lexems({
    { ID,           std::regex( R"([a-zA-Z][a-zA-Z0-9_]*)" )            },
    { DOUBLE_DIGIT, std::regex( R"((0|([1-9][0-9]*))\.*[0-9]*)" )       }, // can be 0 but can't start with 0
    { INT_DIGIT,    std::regex( R"(0|([1-9][0-9]*))" )                  }, // can be 0 but can't start with 0
    { STRING,       std::regex( R"("[^"]*")" )                          },
    { BOOL,         std::regex( R"((true)|(false))" )                   },
    { KEY_WORD,     std::regex( R"((func)|(if)|(else)|(while)|(for))" ) },
    { L_BRACKET,    std::regex( R"(\()" )                               }, // can be only (
    { R_BRACKET,    std::regex( R"(\))" )                               }, // can be only )
    { L_BRACE,      std::regex( R"(\{)" )                               }, // can be only {
    { R_BRACE,      std::regex( R"(\})" )                               }, // can be only }
    { INCREMENT_OP, std::regex( R"(\+\+)" )                             },
    { DECREMENT_OP, std::regex( R"(\-\-)" )                             },
    { OPERATOR,     std::regex( R"([\+\-\*\/=])" )                      },
    { COMMA,        std::regex( R"(,)")                                 },
    { SEMICOLON,    std::regex( R"(;)" )                                },
}) {

}

Lexer::~Lexer() {

}

void Lexer::scanFile(const std::string& filename) {
    std::ifstream file("../src/" + filename);

    if (!file.is_open()) {
        throw std::invalid_argument( "can't open file " + filename );
    }

    std::string line;
    for (int i = 0; getline(file, line); i++) {
        if (!line.empty()) {
            std::string oldStr;

            for (int startIndex = 0, endIndex = 1; endIndex <= line.size(); endIndex++) {
                if (startIndex < endIndex) {
                    std::string newStr = line.substr(startIndex, endIndex - startIndex);

                    if (newStr == " ") {
                        startIndex++;
                        continue;
                    } else if (std::regex_match(newStr, std::regex(R"(("[^"]*)|(\|)|(&))"))) {
                        continue;
                    } else if (!checkToken(newStr)) {
                        addToken(oldStr.empty() ? newStr : oldStr, i);
                        endIndex--;
                        startIndex = endIndex;
                    } else if (endIndex == line.size()) {
                        addToken(newStr, i);
                        addToken(";", i);
                    }

                    oldStr = newStr;
                }
            }
        }
    }

    file.close();
}

bool Lexer::checkToken(const std::string& input) {
    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            return true;
        }
    }
    return false;
}

void Lexer::addToken(const std::string& input, const int& lineNum) {
    bool didFind = false;
    TokenType type;

    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            type = lexem.first;
            didFind = true;
        }
    }

    if (didFind) {
        if (type == KEY_WORD) {
            type = checkKeyWord(input);
        } else if (type == OPERATOR) {
            type = checkOperator(input);
        }

        tokens.emplace_back(type, input);
    } else {
        throw std::invalid_argument("wrong syntax at line " + std::to_string(lineNum + 1) + ": " + input);
    }
}

std::list<Token> Lexer::getTokens() {
    return tokens;
}

TokenType Lexer::checkKeyWord(const std::string& input) {
    if (input == "func") {
        return FUNC_KW;
    } else if (input == "if") {
        return IF_KW;
    } else if (input == "else") {
        return ELSE_KW;
    } else if (input == "while") {
        return WHILE_KW;
    } else {
        return FOR_KW;
    }
}

TokenType Lexer::checkOperator(const std::string& input) {
    if (input == "=") {
        return ASSIGN_OP;
    } else if (input == "+") {
        return SUM_OP;
    } else if (input == "-") {
        return SUB_OP;
    } else if (input == "*") {
        return MULT_OP;
    } else {
        return DIV_OP;
    }
}
