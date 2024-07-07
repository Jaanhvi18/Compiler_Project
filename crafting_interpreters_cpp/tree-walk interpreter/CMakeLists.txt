#Usage Documentation:
# 1) Within the build file run cmake --build .

cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 11)
project(tree_walker)
add_executable(tree_walker main.cpp TreeWalker.cpp Scanner.cpp Token.h TokenType.h)

