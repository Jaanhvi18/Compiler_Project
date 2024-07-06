#include "Token.h"
#include <string>
#include <vector>
#include <unordered_map>
// #include "Keywords.h"

class Scanner
{

public:
    Scanner(std::string src) : source(src){};
    ~Scanner(){};

    std::vector<Token> scanTokens();

private:
    std::string source;
    std::vector<Token> tokens;
    // std::unordered_map<const char*, int> keywords = {
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    //     {"and",AND},
    // };

    int start = 0;
    int current = 0;
    int line = 1;

    char putback = 0; // Variable to hold the putback character

    bool atEnd();

    void scanToken();

    char advance();
    void putBack(char);

    void addToken(int);      // takes in TokenType enum value
    void addToken(int, int); // token type and "object"

    bool match(char);
    char peek();
    char peekNext();
    int scanInt(char);
    int chrpos(const std::string &, char);
    int lookupKeyword(const std::string &text);
};