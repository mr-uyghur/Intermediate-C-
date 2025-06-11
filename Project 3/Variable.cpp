//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#include "Variable.h"

// Initializes variable with name and value
Variable::Variable(const std::string& varName, int val)
    : name(varName), value(val), isDefined(true) {}

std::string Variable::getName() const {
    return name;
}

int Variable::getValue() const {
    return value;
}

bool Variable::defined() const {
    return isDefined;
}

// Sets or updates value
void Variable::setValue(int val) {
    value = val;
    isDefined = true;
}

// By default, variables are not constants
bool Variable::isConstant() const {
    return false;
}