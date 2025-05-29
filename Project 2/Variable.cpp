#include "Variable.h"

// Constructor initializes variable with name and value, marks it as defined
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

// Assigns a new value and marks the variable as defined
void Variable::setValue(int val) {
    value = val;
    isDefined = true;
}
