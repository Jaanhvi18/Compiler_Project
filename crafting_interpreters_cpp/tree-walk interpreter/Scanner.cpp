#include "Scanner.h"
#include "TokenType.h"
#include "Token.h"
#include <cctype> // For isdigit
#include <unordered_map>
#include <iostream>

Scanner::Scanner()
{
    // keywords is a datamember of scanner and should be declared within its scope
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
        {"while", WHILE}};
}

// allows one instances of scanner, fead in source when needed
void Scanner::inputSource(const std::string &src)
{
    source = src;
}

std::vector<Token> Scanner::scanTokens()
{
    // process the file
    start = 0;
    current = 0;
    tokens.clear();
    while (!atEnd())
    {
        start = current;
        scanToken();
    }

    // eof token simplifies later process
    tokens.push_back(Token(EOF_TOKEN, "", 0, 1));
    return tokens;
}

bool Scanner::atEnd()
{
    return current >= source.length();
}

void Scanner::scanToken()
{
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
    // mathematical operators
    case '.':
        addToken(DOT);
        break;
    case '-':
        if (match('-'))
        {
            addToken(DECREMENT);
        }
        else
        {
            addToken(MINUS);
        }
        break;
    case '+':
        if (match('+'))
        {
            addToken(INCREMENT);
        }
        else
        {
            addToken(PLUS);
        }
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '*':
        addToken(STAR);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !atEnd())
                advance();
        }
        else
        {
            addToken(SLASH);
        }
        break;
    case '%':
        addToken(MODULO);
        break;

    // logical operators
    case '!':
        addToken(match('=') ? BANG_EQUAL : BANG);
        break;
    case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
    case '"':
        scanString();
        break;
    case ' ':
    case '\r':
    case '\f':
    case '\t':
        // ignoring whitespace
        break;
    case '\n':
        line++;
        break;
    default:
        if (isdigit(cur))
        { // number case
            int value = scanInt(cur);
            addToken(NUMBER, value);
        }
        else if (isalpha(cur) || cur == '_')
        { // identifier case
            while (!atEnd() && (isalnum(peek()) || peek() == '_'))
            {
                advance();
            }

            std::string identifier = source.substr(start, current - start);
            int keywordType = lookupKeyword(identifier);
            if (keywordType != -1)
            {
                addToken(keywordType);
            }
            else
            {
                addToken(IDENTIFIER);
            }
        }
        else
        {
            printf("Unrecognized character %c on line %d\n", cur, line);
            exit(1);
        }
        break;
    }
}

char Scanner::advance()
{
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

bool Scanner::match(char expected)
{
    if (atEnd())
        return false;
    if (source.at(current) != expected)
        return false;

    current++;
    return true;
}

void Scanner::putBack(char c)
{
    putback = c; // Store the character in putback
}

void Scanner::addToken(int type)
{
    addToken(type, 0);
}

void Scanner::addToken(int type, int literal)
{

    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::addToken(int type, std::string &literal)
{
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

// Scan and return an integer literal
// value from the input file.
int Scanner::scanInt(char c)
{
    while (isdigit(peek()))
        advance();

    if (peek() == '.' && isdigit(peekNext()))
    {
        advance();

        while (isdigit(peek()))
            advance();
    }
    return std::stoi(source.substr(start, current - start));
}

// Return the position of character c
int Scanner::locateChar(const std::string &s, char c)
{
    // this code was overcommented

    auto pos = s.find(c); // first instance of character
    if (pos == std::string::npos)
        return -1;
    return static_cast<int>(pos);
}

void Scanner::scanString()
{
    while (peek() != '"' && !atEnd())
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (atEnd())
    {
        std::cerr << "Unfinished String" << std::endl;
        exit(1);
    }

    advance();

    std::string val = source.substr(start + 1, (current - 1) - start + 1).c_str();
    addToken(STRING, val);
}

int Scanner::lookupKeyword(const std::string &text)
{
    auto it = keywords.find(text);
    if (it == keywords.end())
        return -1;
    return it->second; // not a keyword
}

void Scanner::identifier()
{
    while (isalnum(peek()))
        advance();
    addToken(IDENTIFIER);
}

// chcks if the cur postion is in the end of the src
// returns the char at the cur po in the source.
char Scanner::peek()
{
    if (atEnd())
        return '\0';
    return source.at(current);
}

char Scanner::peekNext()
{
    if (current + 1 >= source.length())
        return '\0';
    return source.at(current + 1);
}
