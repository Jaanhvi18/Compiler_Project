#pragma once

#include "Token.h"
#include "Expr.hpp"
#include <vector>
#include <initializer_list>


class Parser {
public:
    Parser(std::vector<Token>& tkns) : tokens(tkns) {}
    ~Parser() {}


private:
    std::vector<Token> tokens;
    int current = 0;


    ExprPtr expression();
    ExprPtr equality();
    bool match(std::initializer_list<TokenType>);
    bool check(TokenType);
    TokenPtr advance();
    bool atEnd();
    TokenPtr peek();
    TokenPtr previous();

    ExprPtr comparison();
    ExprPtr term();
    ExprPtr factor();
};