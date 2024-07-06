#include "TreeWalker.h"
#include <iostream>
#include <fstream>
#include <string>

void TreeWalker::run(const char *file)
{
    // given this should exist in the root file
    const std::string relative_path = std::string("../test_files/") + std::string(file);
    const std::string source = read_file(relative_path);
    std::cout << source << std::endl;
}

// string does not have a namespace
// using string& to avoid  copying and make sure that the function does not modify the original string.
void TreeWalker::error(int line, const std::string &message)
{
    // implementation of the error function
    std::cerr << "Error at line " << line << ": " << message << std::endl;
}

// reading in the file
// using string& to avoid  copying and make sure that the function does not modify the original string.
std::string TreeWalker::read_file(const std::string &file)
{
    std::ifstream file_reader(file);
    
    if (!file_reader) {
        error(0, "Unable to open file");
        exit(1);
    }
    std::string source = std::string((std::istreambuf_iterator<char>(file_reader)),
                                std::istreambuf_iterator<char>());
   
    return source;
}
