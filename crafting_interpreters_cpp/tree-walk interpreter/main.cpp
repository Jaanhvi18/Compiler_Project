/*
    This is the entry point for our tree walk interpreter.
    It takes the file name to be compiled as the command line argument
    currently  

*/

#include "TreeWalker.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr<<"Enter a single argument containing source file name"<<std::endl;
        exit(1);
    }
    TreeWalker compiler = TreeWalker();
    compiler.run(argv[1]);
}


