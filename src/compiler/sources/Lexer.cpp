//
// Created by Ivan Markov on 05.03.2022.
//

#include <fstream>
#include "Lexer.h"
#include "ExcLexer.h"

Lexer::Lexer(): lexems({
    {LEX_ONE_CHAR,     std::regex( R"([!;,\+\-\*\/=\}\{\)\(<>])" )                      },
    {LEX_TWO_CHAR,     std::regex( R"((\-\-)|(\+\+)|(&&)|(\|\|)|(==)|(!=)|(<=)|(>=))" ) },
    {LEX_KEY_WORD,     std::regex( R"((func)|(if)|(else)|(while)|(true)|(false))" )     },
    {LEX_STRING,       std::regex( R"("[^"]*")" )                                       },
    {LEX_INT_DIGIT,    std::regex( R"(0|([1-9][0-9]*))" )                               },
    {LEX_DOUBLE_DIGIT, std::regex( R"((0|([1-9][0-9]*))\.*[0-9]*)" )                    },
    {LEX_ID,           std::regex( R"([a-zA-Z][a-zA-Z0-9_]*)" )                         },
}) {

}

Lexer::~Lexer() {

}

void Lexer::scanFile(const std::string& filename) {
    std::ifstream file("../src/" + filename);

    if (!file.is_open()) {
        file.close();
        throw ExcLexer("can't open file " + filename, 0);
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
                        addToken(oldStr.empty() ? newStr : oldStr, i + 1);
                        endIndex--;
                        startIndex = endIndex;
                    } else if (endIndex == line.size()) {
                        addToken(newStr, i + 1);
                        tokens.emplace_back(SEMICOLON, ";", i + 1);
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
    for (const auto& lexem: lexems) {
        if (regex_match(input, lexem.second)) {
            switch (lexem.first) {
                case LEX_ONE_CHAR:
                    tokens.emplace_back(checkOneChar(input), input, lineNum);
                    break;
                case LEX_TWO_CHAR:
                    tokens.emplace_back(checkTwoChar(input), input, lineNum);
                    break;
                case LEX_KEY_WORD:
                    tokens.emplace_back(checkKeyWord(input), input, lineNum);
                    break;
                case LEX_STRING:
                    tokens.emplace_back(STRING, input, lineNum);
                    break;
                case LEX_INT_DIGIT:
                    tokens.emplace_back(INT_DIGIT, input, lineNum);
                    break;
                case LEX_DOUBLE_DIGIT:
                    tokens.emplace_back(DOUBLE_DIGIT, input, lineNum);
                    break;
                case LEX_ID:
                    tokens.emplace_back(ID, input, lineNum);
                    break;
            }
            return;
        }
    }

    throw ExcLexer("wrong lexem '" + input + "'", lineNum);
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
        return BOOL;
    }
}

TokenType Lexer::checkOneChar(const std::string& input) {
    if (input == ";") {
        return SEMICOLON;
    } else if (input == ",") {
        return COMMA;
    } else if (input == "{") {
        return L_BRACE;
    } else if (input == "}") {
        return R_BRACE;
    } else if (input == "(") {
        return L_BRACKET;
    } else if (input == ")") {
        return R_BRACKET;
    } else if (input == "=") {
        return ASSIGN_OP;
    } else if (input == "<") {
        return SMALLER_OP;
    } else if (input == ">") {
        return GREATER_OP;
    } else if (input == "+") {
        return SUM_OP;
    } else if (input == "-") {
        return SUB_OP;
    } else if (input == "*") {
        return MULT_OP;
    } else if (input == "/") {
        return DIV_OP;
    } else {
        return NOT_OP;
    }
}

TokenType Lexer::checkTwoChar(const std::string &input) {
    if (input == "--") {
        return DECREMENT_OP;
    } else if (input == "++") {
        return INCREMENT_OP;
    } else if (input == "&&") {
        return AND_OP;
    } else if (input == "||") {
        return OR_OP;
    } else if (input == "==") {
        return EQUAL_OP;
    } else if (input == "!=") {
        return NOT_EQUAL_OP;
    } else if (input == "<=") {
        return SMALLER_OR_EQUAL_OP;
    } else {
        return GREATER_OR_EQUAL_OP;
    }
}
