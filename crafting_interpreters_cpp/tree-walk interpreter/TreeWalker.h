#pragma once

#include <string>
#include "Scanner.h"
#include "ErrorReporter.h"

class TreeWalker {
public:
    TreeWalker();
    ~TreeWalker() {}

    // this will ensure that we don’t try to execute code that has a known error
    void run(const std::string&);
    void runFile(const char *);
    void runPrompt();
    // using string& to avoid copying the stringand make sure that the function does not modify the original string.
    // or else if we use std::string we would end up making a copy of the string and other would lead to better performance

private:
    ErrorReporter errorReporter;
    Scanner* scanner;
    std::string readFile(const std::string &file);
  
};
