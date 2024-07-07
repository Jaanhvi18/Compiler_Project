#include "TreeWalker.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()



void TreeWalker::run(const std::string& source) {
    std::cout<<"source line: " <<source<<std::endl;
    scanner.inputSource(source);
    std::vector<Token> tokens = scanner.scanTokens();
    std::cout<<tokens.size()<<" Tokens detected (including eof)"<<std::endl;
    for (Token token : tokens) {
        std::cout<<token.getLexeme()<<std::endl;
    }
    tokens.clear();
}


void TreeWalker::runPrompt() {
    std::string currentLine;
    while (true) {
        std::cout<<"> ";
        getline(std::cin,currentLine);
        if (currentLine == "exit")
            break;
        run(currentLine);
    }
}

void TreeWalker::runFile(const char *file) {
    // given this should exist in the root file
    std::string relative_path = std::string("../test_files/") + std::string(file);
    std::string source = readFile(relative_path);

    std::cout<<source<<std::endl;
    //run(source);
}

// reading in the file
std::string TreeWalker::readFile(const std::string &file) {
    std::ifstream read(file);

    if (!read.is_open())
    {
        std::cerr<<"Unable to Read Source File"<<std::endl;
        exit(1);
    }

    std::string source = std::string((std::istreambuf_iterator<char>(read)),
                                     std::istreambuf_iterator<char>());
    read.close();
    return source;
}

void TreeWalker::error(int line, const std::string &message) {
    // Call report to display the error message
    report(line, "", message);
}

void TreeWalker::report(int line, const std::string &where, const std::string &message) {
    // Implementation of the report function
    std::cerr << "Error at line " << line << where << ": " << message << std::endl;
}
