#include "Parser.h"


ExprPtr Parser::expression() {
    return equality();
}

ExprPtr Parser::equality() {
    ExprPtr expr = comparison();
    while (match({BANG_EQUAL, EQUAL_EQUAL})) {
        TokenPtr oprtr = previous();
        ExprPtr right = comparison();
        expr = std::make_shared<Expr>(Binary(expr,oprtr,right));
    }
    return expr;
}

ExprPtr Parser::comparison() {
    ExprPtr expr = term();

    while (match({GREATER,GREATER_EQUAL,LESS,LESS_EQUAL})) {
        TokenPtr oprtr = previous();
        ExprPtr right = term();
        expr = std::make_shared<Expr>(Binary(expr,oprtr,right));
    }
    return expr;
}

ExprPtr Parser::term() {
    ExprPtr expr = factor();

    while (match({PLUS,MINUS})) {
        TokenPtr oprtr = previous();
        ExprPtr right = factor();
        expr = std::make_shared<Expr>(Binary(expr,oprtr,right));
    }
    return expr;
}

ExprPtr Parser::factor() {
    ExprPtr expr = unary();

    while (match({SLASH,STAR,MODULO})) {
        TokenPtr oprtr = previous();
        ExprPtr right = unary();
        expr = std::make_shared<Expr>(Binary(expr,oprtr,right));
    }
    return expr;
}


ExprPtr Parser::unary() {
    if (match({BANG, MINUS})) {
        TokenPtr oprtr = previous();
        ExprPtr right = unary();
        return std::make_shared<Expr>(Unary(oprtr,right));
    }
    return primary();
}


ExprPtr Parser::primary() {
    if (match({FALSE}))
        return std::make_shared<Expr>(Literal(std::make_shared<TokenType>(FALSE)));
    if (match({TRUE}))
        return std::make_shared<Expr>(Literal(std::make_shared<TokenType>(TRUE)));
    if (match({NIL})) 
        return std::make_shared<Expr>(Literal(std::make_shared<TokenType>(NIL)));
    if (match({NUMBER})) 
        return std::make_shared<Expr>(Literal(std::make_shared<TokenType>(previous()->getIntLiteral())));
    if (match({STRING})) 
        return std::make_shared<Expr>(Literal(std::make_shared<TokenType>(previous()->getStringLiteral())));
    if (match({LEFT_PAREN})) {
        ExprPtr expr = expression();
        consume(RIGHT_PAREN,"Expect ')' after expression");
        return std::make_shared<Expr>(Grouping(expr));
    }
}

//enum as a type? may have to switch to int
bool Parser::match(std::initializer_list<TokenType> types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance();
            return true;
        }
    }
    return false;
}

bool Parser::check(TokenType type) {
    if (atEnd()) {
        return false;
    }
    return peek()->getType() == type;
}

TokenPtr Parser::advance() {
    if (!atEnd())
        current++;
    return previous();
}

bool Parser::atEnd() {
    return peek()->getType() == EOF;
}

TokenPtr Parser::peek() {
    return std::make_shared<Token>(tokens.at(current));
}


TokenPtr Parser::previous() {
    return std::make_shared<Token>(tokens.at(current - 1));
}


//error handling is becoming a pain
TokenPtr Parser::consume(TokenType type, std::string message) {
    if (check(type))
        return advance();
    
    throw error(peek(),message);
}

