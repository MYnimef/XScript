//
// Created by Ivan Markov on 06.03.2022.
//

#pragma once

#include <map>
#include <list>
#include <stack>
#include <regex>
#include "Token.h"
#include "Exp.h"
#include "Node.h"

class Parser final {
private:
    enum GrammarType {
        GR_FUNC,
        GR_VAR_ASSIGNMENT_COMPLEX,
        GR_VAR_ASSIGNMENT,
        GR_VAR_INCREMENT_DECREMENT,
        GR_IF,
        GR_LOOP_WHILE,
        GR_FUNC_DEFINITION,
        };

    const std::string val;
    const std::map<GrammarType, std::regex> syntax;
    Node* tree;
    std::map<std::string, Node*>* functions;

    void addTokensLine(std::list<Token>&);
    void generateExpression(std::list<Token>&);
    GrammarType checkGrammar(std::list<Token>&);

    void parseAssignmentComplex(std::list<Token>&);
    void parseAssignment(std::list<Token>&);
    void parseIncrementDecrement(std::list<Token>&);
    std::list<Exp*> parseOperations(std::list<Token>&);
    void parseFuncDefinition(std::list<Token>&);
    void parseIf(std::list<Token>&);
    void parseWhile(std::list<Token>&);
    void parseFunctionCall(std::list<Token>&);

    void subOperations(std::list<Exp*>& expressions, std::list<Token>& localTokens);
    Exp* subFunction(std::list<Token>&);

    std::list<Exp*> toPostfix(std::list<Exp*>&);
    static short operatorPriority(const ExpressionType& type);
    Node* addNodeExpr(const std::list<Exp*>&);

public:
    explicit Parser(
            Node* node,
            std::map<std::string, Node*>* functions
            );
    explicit Parser(
            Node* node,
            const std::string& actions,
            const std::map<GrammarType, std::regex>&
            );
    ~Parser();

    void addTokens(const std::list<Token>&);
    Node* getTree();
};