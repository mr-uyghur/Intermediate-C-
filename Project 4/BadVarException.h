//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef BADVAREXCEPTION_H
#define BADVAREXCEPTION_H

#include <stdexcept>
#include <string>

// Custom exception class that inherits from std::runtime_error
// Used to throw exceptions for invalid variable names or negative values
class BadVarException : public std::runtime_error {
public:
    BadVarException(const std::string& message) : std::runtime_error(message) {}
};

#endif
