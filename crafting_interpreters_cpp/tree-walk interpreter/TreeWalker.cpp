#include "TreeWalker.h"
#include <iostream>
#include <fstream>

void TreeWalker::run(const char* file) {
    //given this should exist in the root file
    std::string relative_path = std::string("../test_files/") + std::string(file);
    std::string source = readFile(relative_path);
    std::cout<<source<<std::endl;
}

// reading in the file
std::string TreeWalker::readFile(const std::string& file) {
    std::ifstream read(file);

    if (!read.is_open()) {
        std::cerr<<"Unable to read file"<<std::endl;
        exit(1);
    }

    std::string source = std::string((std::istreambuf_iterator<char>(read)),
                                std::istreambuf_iterator<char>());
    read.close();
    return source;
}
