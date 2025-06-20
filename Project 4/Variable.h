//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

// Base class representing a variable (or constant, through inheritance)
class Variable {
protected:
    std::string name;  // Variable name
    int value;         // Integer value
    bool isDefined;    // Flag to check if variable has a value

public:
    Variable(const std::string& varName, int val);
    virtual ~Variable() {}

    std::string getName() const;
    int getValue() const;
    bool defined() const;

    virtual void setValue(int val);         // Sets value (can be overridden)
    virtual bool isConstant() const;        // Identifies if it's a constant
};

#endif
