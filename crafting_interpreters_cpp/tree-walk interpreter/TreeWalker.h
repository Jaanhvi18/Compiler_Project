#pragma once

#include <string>

class TreeWalker {
public:
    TreeWalker() {} // takes the command line argument file as input
    ~TreeWalker() {}

    void run(const char *);
    // using string& to avoid copying the stringand make sure that the function does not modify the original string.
    // or else if we use std::string we would end up making a copy of the string and other would lead to better performance
    void error(int line, const std::string &message);

private:
    void report(int line, const std::string &where, const std::string &message);
    std::string readFile(const std::string &file);
};
