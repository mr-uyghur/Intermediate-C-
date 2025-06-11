//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 
#include "Constant.h"
#include <iostream>

// Constructor calls base class constructor
Constant::Constant(const std::string& name, int val)
    : Variable(name, val) {}

// Prevents reassignment by printing an error
void Constant::setValue(int val) {
    std::cout << "Invalid assignment. Cannot assign new value to a constant." << std::endl;
}

// Used to differentiate in output
bool Constant::isConstant() const {
    return true;
}