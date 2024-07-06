#pragma once 
#include "TokenType.h"
#include <string>

class Token {
public:
    Token(int type, const char* lexeme, int literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->line = line;
    }
    ~Token() {}

    std::string toString() {
        return std::to_string(type) + " " + std::string(lexeme) + " " + std::to_string(literal);
    }

private:
    int type;
    const char* lexeme;
    int literal; //type unclear so like an intvalue field will hold the value of the integer that we scanned in
    int line;

};