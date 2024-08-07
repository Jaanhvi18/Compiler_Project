#include "Token.h"
#include "ErrorReporter.h"
#include <string>
#include <vector>
#include <unordered_map>
// #include "Keywords.h"

class Scanner {

public:
    Scanner();
    Scanner(ErrorReporter&);
    ~Scanner(){};

    std::vector<Token> scanTokens();
    void inputSource(const std::string&);

private:
    std::string source;
    std::vector<Token> tokens;
    std::unordered_map<std::string,int> keywords;

    ErrorReporter& errorReporter;


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
    void addToken(int type, const std::string &literal);

    bool match(char);
    char peek();
    char peekNext();
    void scanInt();
    void scanString();
    int locateChar(const std::string &, char);
    int lookupKeyword(const std::string &text);
    void identifier();

};