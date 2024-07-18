#include <vector>
#include <string>
#include <iostream>


#pragma once

class ErrorReporter {
public:

    ErrorReporter() {}
    ~ErrorReporter() {}

    void storeError(int line, std::string message) {
        errorList.push_back(Error(line,message));
    }

    bool containsErrors() {
        return !errorList.empty();
    }

    void clearErrors() {
        errorList.clear();
    }

    void reportErrors() {
        std::cout<<"Compilation Errors: "<<std::endl;
        for (Error e : errorList) {
            std::cout<<e.format()<<std::endl;
        }
    }

private:
    class Error {
    public:
        Error(int line, std::string msg) : line(line), message(msg) {}
        ~Error() {}

        std::string format() {
            std::string output = "[line " + std::to_string(line) + "] " + message;
            return output;
        }
    private:
        int line;
        std::string message;
    };

    std::vector<Error> errorList;

};