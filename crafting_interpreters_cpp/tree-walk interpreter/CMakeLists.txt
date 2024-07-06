#Usage Documentation:
# 1) Within the build file run cmake --build .

cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 11)
project(tree_walker)
add_executable(tree_walker main.cpp TreeWalker.cpp)


#have to manually run the executable with comamnd line arguments
#add_custom_command(
#    TARGET tree_walker
#    POST_BUILD
#    COMMAND tree_walker
#)