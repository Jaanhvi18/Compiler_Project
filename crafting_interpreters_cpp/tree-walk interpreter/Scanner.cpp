#include "Scanner.h"
#include "TokenType.h"
#include "Token.h"
#include <cctype> // For isdigit
#include <unordered_map>

Scanner::Scanner() {
    //keywords is a datamember of scanner and should be declared within its scope
    keywords = {
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
}


//allows one instances of scanner, fead in source when needed
void Scanner::inputSource(const std::string& src) {
    source = src;
}

std::vector<Token> Scanner::scanTokens() {
    // process the file
    while (!atEnd())
    {
        start = current;
        scanToken();
    }

    // eof token simplifies later process
    tokens.push_back(Token(EOF_TOKEN, "", 0, 1));
    return tokens;
}

bool Scanner::atEnd() {
    return current >= source.length();
}

void Scanner::scanToken() {
    // Checks and consumes the current token
    char cur = advance();

    switch (cur)
    {
    // The basic math operators: *, /, +, and -
    case '(':
        addToken(LEFT_PAREN);
        break;
    case ')':
        addToken(RIGHT_PAREN);
        break;
    case '{':
        addToken(LEFT_BRACE);
        break;
    case '}':
        addToken(RIGHT_BRACE);
        break;
    case ',':
        addToken(COMMA);
        break;
    case '.':
        addToken(DOT);
        break;
    case '-':
        addToken(MINUS);
        break;
    case '+':
        addToken(PLUS);
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '*':
        addToken(STAR);
        break;
    case '%':
        addToken(MODULO);
        break;
    case ' ':
    case '\r':
    case '\t':
        // ignoring whitespace
        break;
    case '\n':
        line++;
        break;
    default: //consider refactoring below behavior into a separate function
        if (isdigit(cur)) //number case
        {
            int value = scanInt(cur);
            // Aaccounting for an adding the int literal token here
            addToken(NUMBER, value);
        }
        else if (isalpha(cur) || cur == '_') //identifer case
        {
            // Consume the entire identifier
            while (!atEnd() && (isalnum(peek()) || peek() == '_'))
            {
                advance();
            }

            std::string identifier = source.substr(start, current - start);
            int keywordType = lookupKeyword(identifier);
            if (keywordType != -1)
            {
                // It's a keyword
                addToken(keywordType);
            }
            else
            {
                addToken(IDENTIFIER);
            }
        }
        else
        {
            // Handle other cases, such as identifiers
            printf("Unrecognized character %c on line %d\n", cur, line);
            exit(1);
        }
        break;
    }
}

char Scanner::advance() {
    // we need to be able to baccktrack chars if we read more than we shoudl
    if (putback != 0)
    {
        char temp = putback; // checking if there is a putback char
        putback = 0;         // using the putback char
        return temp;
    }
    char c = source.at(current++); // read the next char from the source
    if (c == '\n')
    {
        line++; // increment line count on newline
    }
    return c;
}


void Scanner::putBack(char c) {
    putback = c; // Store the character in putback
}


void Scanner::addToken(int type) {
    addToken(type, 0);
}


void Scanner::addToken(int type, int literal) {
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text.c_str(), literal, line));
}

// Scan and return an integer literal
// value from the input file.
int Scanner::scanInt(char c) {
    int val = 0;
    int k;

    // Convert each character into an int value
    while ((k = locateChar("0123456789", c)) >= 0)
    {
        val = val * 10 + k;
        c = advance();
    }

    // We hit a non-integer character, put it back.
    putBack(c);
    return val;
}

// Return the position of character c
int Scanner::locateChar(const std::string &s, char c) {
    //this code was overcommented

    auto pos = s.find(c); //first instance of character
    if (pos == std::string::npos)
        return -1;
    return static_cast<int>(pos);
}


int Scanner::lookupKeyword(const std::string &text) {
    auto it = keywords.find(text);
    if (it == keywords.end())
        return -1;
    return it->second; // not a keyword
}


void Scanner::identifier() {
    while (isalnum(peek()))
        advance();
    addToken(IDENTIFIER);
}

// chcks if the cur postion is in the end of the src
// returns the char at the cur po in the source.
char Scanner::peek() {
    if (atEnd())
        return '\0';
    return source.at(current);
}


//the builtin alnum works just fine. No point in adding additional code to solve the same simple problem

/* bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}


bool Scanner::isDigit(char c) {
    return c >= '0' && c <= '9';
}


bool Scanner::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
} */



