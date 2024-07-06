#include "TreeWalker.h"
#include <iostream>
#include <fstream>
#include <string>

void TreeWalker::run(const char *file)
{
    // given this should exist in the root file
    std::string relative_path = std::string("../test_files/") + std::string(file);
    std::string source = read_file(relative_path);
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
    std::string source;

    if (file_reader.is_open())
    {
        while (!file_reader.eof())
            source += file_reader.get();
    }
    if (file_reader.fail() && !file_reader.eof())
    {
        error(0, "Error reading file" + file);
        exit(1);
    }

    else
    {
        std::cerr << "Unable to read file" << std::endl;
        exit(1);
    }
    source.pop_back(); // reads in additional ? at the end of the file
    return source;
}
