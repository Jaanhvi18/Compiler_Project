#include "Token.h"
#include <string>
#include <vector>
#include <unordered_map>

class Scanner {

public:
    Scanner(std::string src) : source(src) {};
    ~Scanner() {};

    std::vector<Token> scanTokens();

private:

    std::string source;
    std::vector<Token> tokens;
    std::unordered_map<const char*, int> keywords = {
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
        {"and",AND},
    };

    int start = 0;
    int current = 0;
    int line = 1;

    bool atEnd();
    void scanToken();
    char advance();
    
    void addToken(int); //takes in TokenType enum value
    void addToken(int,int); //token type and "object"

    bool match(char);
    char peek();
    char peekNext();
    
    

};