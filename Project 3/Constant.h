//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef CONSTANT_H
#define CONSTANT_H

#include "Variable.h"

// Represents a constant (inherits from Variable)
class Constant : public Variable {
public:
    Constant(const std::string& name, int val); // constructor
    void setValue(int val) override; // override to prevent reassignment
    bool isConstant() const override; // identifies constant
};

#endif