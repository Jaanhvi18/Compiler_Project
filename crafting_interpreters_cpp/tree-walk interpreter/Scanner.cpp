#include "Scanner.h"
#include "TokenType.h"

std::vector<Token> Scanner::scanTokens() {
    //process the file
    while (!atEnd()) {
        start = current;
        scanToken();
    }

    //eof token simplifies later process
    tokens.push_back(Token(EOF,"",0,1));
    return tokens;
}

bool Scanner::atEnd() {
    return current >= source.length();
}


void Scanner::scanToken() {
    //checks and consumes the current token
    char cur = advance();
    
    switch (cur) {
      case '(': addToken(LEFT_PAREN); break;
      case ')': addToken(RIGHT_PAREN); break;
      case '{': addToken(LEFT_BRACE); break;
      case '}': addToken(RIGHT_BRACE); break;
      case ',': addToken(COMMA); break;
      case '.': addToken(DOT); break;
      case '-': addToken(MINUS); break;
      case '+': addToken(PLUS); break;
      case ';': addToken(SEMICOLON); break;
      case '*': addToken(STAR); break; 
      case '%': addToken(MODULO); break;
      default:
        //this is where we want our errors to be declared
        break;
    }
}


char Scanner::advance() {
    return source.at(current++);
}


void Scanner::addToken(int type) {
    addToken(type,0);
}


void Scanner::addToken(int type, int literal) {
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type,text.c_str(),literal,line));
}