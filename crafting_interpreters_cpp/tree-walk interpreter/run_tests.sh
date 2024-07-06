#!/bin/bash

# Set the script to exit immediately if any command fails
set -e

# Define the source files and the output binary
SOURCE_FILES="TreeWalker.cpp test_treewalker.cpp"
OUTPUT_BINARY="test_treewalker"

# Compile the test program
echo "Compiling the test program..."
g++ -o $OUTPUT_BINARY $SOURCE_FILES

# Run the test program
echo "Running the tests..."
./$OUTPUT_BINARY

# Clean up the generated files
echo "Cleaning up..."
rm -f $OUTPUT_BINARY
rm -f test_file.txt

echo "Tests completed successfully!"
