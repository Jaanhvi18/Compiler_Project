#pragma once
#include <string>

class TreeWalker  {
public:

    TreeWalker() {} //takes the command line argument file as input
    ~TreeWalker() {}


    void run(const char*);


private:
    std::string read_file(const std::string);


};