//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

// Base class for both Variable and Constant
class Variable {
protected:
    std::string name; // name of the variable
    int value;        // value assigned
    bool isDefined;   // whether the value is initialized

public:
    Variable(const std::string& varName, int val); // no default constructor
    virtual ~Variable() {}

    std::string getName() const;
    int getValue() const;
    bool defined() const;

    virtual void setValue(int val); // may be overridden by Constant
    virtual bool isConstant() const; // identifies constants
};

#endif