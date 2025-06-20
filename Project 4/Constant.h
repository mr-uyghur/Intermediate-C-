//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef CONSTANT_H
#define CONSTANT_H

#include "Variable.h"

// Derived class representing a constant (cannot be reassigned)
class Constant : public Variable {
public:
    Constant(const std::string& name, int val);
    void setValue(int val) override;     // Prevent reassignment
    bool isConstant() const override;    // Identifies it as a constant
};

#endif
