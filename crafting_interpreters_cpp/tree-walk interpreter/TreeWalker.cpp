#include "TreeWalker.h"
#include <iostream>
#include <fstream>

void TreeWalker::run(const char* file) {
    //given this should exist in the root file
    std::string relative_path = std::string("../test_files/") + std::string(file);
    std::string source = read_file(relative_path);
    std::cout<<source<<std::endl;
}

// reading in the file
std::string TreeWalker::read_file(std::string file) {
    std::ifstream file_reader(file);
    std::string source;
    
    if (file_reader.is_open()) {
        while (!file_reader.eof())
            source += file_reader.get();
    }
    else {
        std::cerr<<"Unable to read file"<<std::endl;
        exit(1);
    }
    source.pop_back(); //reads in additional ? at the end of the file
    return source;
}
