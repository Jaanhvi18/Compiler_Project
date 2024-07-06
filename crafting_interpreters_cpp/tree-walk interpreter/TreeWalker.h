#pragma once
#include <string>

class TreeWalker  {
public:

    TreeWalker(const char*); //takes the command line argument file as input
    ~TreeWalker();


private:
    std::string file_data;


};