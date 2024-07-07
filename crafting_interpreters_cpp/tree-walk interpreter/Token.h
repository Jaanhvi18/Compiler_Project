#pragma once 
#include "TokenType.h"
#include <string>
#include <variant>
#include <iostream>

class Token {
public:
    Token(int type, std::string lexeme, int literal, int line) 
        : Token(type,lexeme,line) {
        this->literal = literal;
    }
    Token(int type, std::string lexeme, std::string literal, int line) 
        : Token(type,lexeme,line) {
        this->literal = literal;
    }
    Token(int type, std::string lexeme,int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->line = line;
    }
    ~Token() {}

    std::string toString() {
       return lexeme;
       /*  std::string literal_str;
        try {
            int asint = std::get<int>(literal);
            literal_str = std::to_string(asint);
        }
        catch (const std::bad_variant_access& ex) {
            literal_str = std::get<std::string>(literal);
        }

        return std::to_string(type) + " " + std::string(lexeme) + " " + literal_str; */
    }

    const std::string& getLexeme() {
        return lexeme;
    }

private:
    int type;
    std::string lexeme;
    std::variant<std::string,int> literal; //type unclear so like an intvalue field will hold the value of the integer that we scanned in
    int line;

};