#include "TreeWalker.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdio> // for remove

// Function to test the error and report functions
void testErrorFunction()
{
    TreeWalker treeWalker;

    // Redirect std::cerr to a stringstream
    std::stringstream buffer;
    std::streambuf *old = std::cerr.rdbuf(buffer.rdbuf());

    // Call the error function
    int testLine = 42;
    std::string testMessage = "Test error message";
    treeWalker.error(testLine, testMessage);

    // Restore the original buffer
    std::cerr.rdbuf(old);

    // Capture the output
    std::string output = buffer.str();
    std::string expectedOutput = "Error at line 42: Test error message\n";

    // Verify the output
    if (output == expectedOutput)
    {
        std::cout << "Error function test passed!" << std::endl;
    }
    else
    {
        std::cout << "Error function test failed!" << std::endl;
        std::cout << "Expected: " << expectedOutput;
        std::cout << "Got: " << output;
    }
}

// Function to test the run function with a non-existent file (indirectly tests readFile)
void testRunFunctionWithNonExistentFile()
{
    TreeWalker treeWalker;

    // Redirect std::cerr to a stringstream
    std::stringstream buffer;
    std::streambuf *old = std::cerr.rdbuf(buffer.rdbuf());

    // Try to run the TreeWalker with a non-existent file
    treeWalker.run("non_existent_file.txt");

    // Restore the original buffer
    std::cerr.rdbuf(old);

    // Capture the output
    std::string output = buffer.str();
    std::string expectedOutput = "Error at line 0: Unable to read file\n";

    // Verify the output
    if (output == expectedOutput)
    {
        std::cout << "Run function with non-existent file test passed!" << std::endl;
    }
    else
    {
        std::cout << "Run function with non-existent file test failed!" << std::endl;
        std::cout << "Expected: " << expectedOutput;
        std::cout << "Got: " << output;
    }
}

// Function to test the run function with an existing file
void testRunFunctionWithExistingFile()
{
    TreeWalker treeWalker;

    // Create a temporary test file
    std::ofstream outFile("test_file.txt");
    outFile << "This is a test file content.";
    outFile.close();

    // Redirect std::cout to a stringstream to capture the output
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    // Run the TreeWalker
    treeWalker.run("test_file.txt");

    // Restore the original buffer
    std::cout.rdbuf(old);

    // Capture the output
    std::string output = buffer.str();
    std::string expectedOutput = "This is a test file content.";

    // Verify the output
    if (output == expectedOutput)
    {
        std::cout << "Run function with existing file test passed!" << std::endl;
    }
    else
    {
        std::cout << "Run function with existing file test failed!" << std::endl;
        std::cout << "Expected: " << expectedOutput;
        std::cout << "Got: " << output;
    }

    // Remove the temporary test file
    std::remove("test_file.txt");
}

// int main()
// {
//     // Run the error function test
//     testErrorFunction();

//     // Run the run function test with a non-existent file
//     testRunFunctionWithNonExistentFile();

//     // Run the run function test with an existing file
//     testRunFunctionWithExistingFile();

//     return 0;
// }
