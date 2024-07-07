/*
    This is the entry point for our tree walk interpreter.
    It aims to support both a simple interactive prompt shell and single
    file compilation support
*/

#include "TreeWalker.h"
#include <iostream>
#include <cstdlib> // for exit()

int main(int argc, char *argv[])
{
    TreeWalker compiler = TreeWalker();
    if (argc == 2)
    {
         compiler.runFile(argv[1]);
    }
    else if (argc == 1) {
        compiler.runPrompt();
    }
    else {
        std::cerr << "Enter a single argument containing source file name" << std::endl;
        // using a non-zero status exit code like the book did to indictae a use error
        return 64;
    }
    
    // and now exit with a zero status code to show success
    return 0;
}
