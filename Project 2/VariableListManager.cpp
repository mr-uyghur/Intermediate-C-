#include "VariableListManager.h"
#include <iostream>
#include <cctype>     // for isdigit()
#include <sstream>    // for stringstream to parse values

// Destructor: deletes all allocated Variable pointers in the list
VariableListManager::~VariableListManager() {
    for (auto var : variableList) {
        delete var;
    }
}

// Searches the vector for a Variable by name
Variable* VariableListManager::findVariable(const std::string& name) {
    for (auto var : variableList) {
        if (var->getName() == name) {
            return var;
        }
    }
    return nullptr; // Not found
}

// Checks if a variable name is valid (must not start with digit)
bool VariableListManager::isValidName(const std::string& name) const {
    return !isdigit(name[0]);
}

// Handles assignment: name = value (value can be number or variable name)
void VariableListManager::assignVariable(const std::string& name, const std::string& value) {
    if (!isValidName(name)) {
        std::cout << "Invalid variable name. Cannot start with a digit." << std::endl;
        return;
    }

    Variable* existing = findVariable(name);

    // Try converting value to integer
    int num;
    std::stringstream ss(value);
    if (ss >> num && ss.eof()) { // value is an integer
        if (existing)
            existing->setValue(num);
        else
            variableList.push_back(new Variable(name, num));

        printVariable(name);
        return;
    }

    // If value is another variable name
    Variable* ref = findVariable(value);
    if (ref) {
        if (existing)
            existing->setValue(ref->getValue());
        else
            variableList.push_back(new Variable(name, ref->getValue()));

        printVariable(name);
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Prints a variable's value in format name(value), or "Undefined"
void VariableListManager::printVariable(const std::string& name) {
    Variable* var = findVariable(name);
    if (var && var->defined())
        std::cout << var->getName() << "(" << var->getValue() << ")" << std::endl;
    else
        std::cout << "Undefined" << std::endl;
}

// Prints all defined variables and count
void VariableListManager::printAll() {
    for (auto var : variableList) {
        if (var->defined())
            std::cout << var->getName() << "(" << var->getValue() << ")" << std::endl;
    }
    std::cout << "Number of variables: " << variableList.size() << std::endl;
}
