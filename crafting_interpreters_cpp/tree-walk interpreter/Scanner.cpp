#include "Scanner.h"
#include "TokenType.h"
#include "Token.h"
#include <cctype>  // For isdigit
#include <unordered_map>


std::unordered_map<std::string, int> keywords = {
    {"and", AND},
    {"class", CLASS},
    {"else", ELSE},
    {"false", FALSE},
    {"for", FOR},
    {"fun", FUN},
    {"if", IF},
    {"nil", NIL},
    {"or", OR},
    {"print", PRINT},
    {"return", RETURN},
    {"super", SUPER},
    {"this", THIS},
    {"true", TRUE},
    {"var", VAR},
    {"while", WHILE}
};

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
    // Checks and consumes the current token
    char cur = advance();

    switch (cur) {
        // The basic math operators: *, /, +, and -
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
        case ' ':
        case '\r':
        case '\t':
            // ignoring whitespace
            break;
        case '\n':
            line++;
            break;
       default:
            if (isdigit(cur)) {
                int value = scanInt(cur);
                // Aaccounting for an adding the int literal token here
                addToken(NUMBER, value);
            } else {
                // Handle other cases, such as identifiers--> still need to do this
                printf("Unrecognized character %c on line %d\n", cur, line);
                exit(1);
            }
            break;
    }
}



char Scanner::advance() {
    // we need to be able to baccktrack chars if we read more than we shoudl
    if (putback != 0){
        char temp = putback; //checking if there is a putback char
        putback = 0; //using the putback char
        return temp;
    }
    char c = source.at(current++); //read the next char from the source
    if (c == '\n'){
        line ++; //increment line count on newline
    }
    return c;
}

void Scanner::putBack(char c) {
    putback = c;  // Store the character in putback
}


void Scanner::addToken(int type) {
    addToken(type,0);
}


void Scanner::addToken(int type, int literal) {
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type,text.c_str(),literal,line));
}

// Scan and return an integer literal
// value from the input file.
int Scanner::scanInt(char c) {
    int val = 0;
    int k;

    // Convert each character into an int value
    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = advance();
    }


  // We hit a non-integer character, put it back.
    putBack(c);
    return val;
}

// Return the position of character c
int Scanner::chrpos(const std::string& s, char c) {
    //using auto instead of std::string::size_type
    auto pos = s.find(c);  //find is looking for the first occurence of the char in string s
    // also dont think we want to define an eexplicit
    if (pos == std::string::npos) { 
        return -1; //c was not found in s
    }
    return static_cast<int>(pos); //returns the position of the first occurence of the char
}




