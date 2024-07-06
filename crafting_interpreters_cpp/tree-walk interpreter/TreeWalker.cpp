#include "TreeWalker.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()

void TreeWalker::run(const char *file)
{
    // given this should exist in the root file
    std::string relative_path = std::string("../test_files/") + std::string(file);
    std::string source = readFile(relative_path);

    // only print the content of the file if no error
    if (error_flag)
    {
        std::cout << source << std::endl;
    }
}

// reading in the file
std::string TreeWalker::readFile(const std::string &file)
{
    std::ifstream read(file);

    if (!read.is_open())
    {
        error(0, "Unable to read file");
        error_flag = true;
        // exit(1);
        return "";
    }

    std::string source = std::string((std::istreambuf_iterator<char>(read)),
                                     std::istreambuf_iterator<char>());
    read.close();
    return source;
}

void TreeWalker::error(int line, const std::string &message)
{
    // Call report to display the error message
    report(line, "", message);
    error_flag = true;
}

void TreeWalker::report(int line, const std::string &where, const std::string &message)
{
    // Implementation of the report function
    std::cerr << "Error at line " << line << where << ": " << message << std::endl;
}
