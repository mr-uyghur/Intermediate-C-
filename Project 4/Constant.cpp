//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 
#include "Constant.h"
#include <iostream>

// Constructor just passes values to base class
Constant::Constant(const std::string& name, int val)
    : Variable(name, val) {}

// Prevents value changes; outputs an error
void Constant::setValue(int val) {
    std::cout << "Invalid assignment. Cannot assign new value to a constant." << std::endl;
}

// Identifies it as a constant
bool Constant::isConstant() const {
    return true;
}
