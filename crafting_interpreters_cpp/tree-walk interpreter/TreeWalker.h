#pragma once

#include <string>
#include "Scanner.h"

class TreeWalker {
public:
    TreeWalker() {} // takes the command line argument file as input
    ~TreeWalker() {}

    // this will ensure that we don’t try to execute code that has a known error
    void run(const std::string&);
    void runFile(const char *);
    void runPrompt();
    // using string& to avoid copying the stringand make sure that the function does not modify the original string.
    // or else if we use std::string we would end up making a copy of the string and other would lead to better performance
    void error(int line, const std::string &message);

private:
    Scanner scanner;
    void report(int line, const std::string &where, const std::string &message);
    std::string readFile(const std::string &file);
  
};
