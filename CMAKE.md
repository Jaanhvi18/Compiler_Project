# C++ Project Setup and Build with CMake

This guide provides instructions for setting up and building your C++ project using CMake.

## Project Structure

```
Compiler_Project/
└── crafting_interpreters_cpp/
    └── tree-walk_interpreter/
        ├── CMakeLists.txt
        ├── src/
        ├── include/
        └── build/
```

## Prerequisites

Ensure you have the following installed:
- CMake (https://cmake.org/)
- A C++ compiler (e.g., GCC, Clang)

## Setup and Build

1. **Navigate to the Project Directory**:

    ```sh
    cd /path/to/Compiler_Project/crafting_interpreters_cpp/tree-walk_interpreter/
    ```

2. **Create and Enter the Build Directory**:

    ```sh
    mkdir -p build
    cd build
    ```

3. **Run CMake**:

    ```sh
    cmake ..
    ```

4. **Build the Project**:

    ```sh
    cmake --build .
    ```

    Output:
    ```
    [ 33%] Building CXX object CMakeFiles/tree_walker.dir/main.cpp.o
    [ 66%] Building CXX object CMakeFiles/tree_walker.dir/TreeWalker.cpp.o
    [100%] Linking CXX executable tree_walker
    [100%] Built target tree_walker
    ```

5. **Run the Executable**:

    ```sh
    ./tree_walker test.txt       
    ```

## Troubleshooting

### CMake Cache Errors

If you encounter `CMakeCache.txt` errors:

1. **Remove the Cache and Files**:

    ```sh
    rm -rf build/CMakeCache.txt build/CMakeFiles
    ```

2. **Re-run CMake**:

    ```sh
    cmake ..
    ```

## Additional Resources

- [CMake Documentation](https://cmake.org/documentation/)
- [C++ Programming Language](https://isocpp.org/)

