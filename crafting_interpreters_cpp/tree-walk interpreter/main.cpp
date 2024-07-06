/*
    This is the entry point for our tree walk interpreter.
    It takes the file name to be compiled as the command line argument
    currently

*/
#include "TreeWalker.h"
#include <iostream>
#include <cstdlib> // for exit()

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Enter a single argument containing source file name" << std::endl;
        // exit(1);
        // using a non-zero status exit code like the book did to indictae a use error
        return 64;
    }
    TreeWalker compiler = TreeWalker();
    compiler.run(argv[1]);

    // and now exit with a zero status code to show success
    return 0;
}
