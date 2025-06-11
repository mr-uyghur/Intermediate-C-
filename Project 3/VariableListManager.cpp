//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#include "VariableListManager.h"
#include <iostream>
#include <sstream>
#include <cctype>

// Destructor to clean up dynamically allocated Variable/Constant objects
VariableListManager::~VariableListManager() {
    for (auto var : variableList)
        delete var;
}

// Validates variable name (not a digit, not "const")
bool VariableListManager::isValidName(const std::string& name) const {
    if (name == "const")
        return false;
    return !isdigit(name[0]);
}

// Searches list for a variable or constant by name
Variable* VariableListManager::findVariable(const std::string& name) {
    for (auto var : variableList) {
        if (var->getName() == name) {
            return var;
        }
    }
    return nullptr;
}

// Assigns value to variable or creates it if new
void VariableListManager::assignVariable(const std::string& name, const std::string& value) {
    if (!isValidName(name)) {
        std::cout << "Invalid variable name. ";
        if (name == "const")
            std::cout << "\"const\" is a reserved keyword." << std::endl;
        else
            std::cout << "Cannot start with a digit." << std::endl;
        return;
    }

    Variable* existing = findVariable(name);

    // Try integer assignment
    int num;
    std::stringstream ss(value);
    if (ss >> num && ss.eof()) {
        if (existing) {
            existing->setValue(num);
        } else {
            variableList.push_back(new Variable(name, num));
        }
        printVariable(name);
        return;
    }

    // Otherwise treat as reference to another variable/constant
    Variable* ref = findVariable(value);
    if (ref) {
        if (existing) {
            existing->setValue(ref->getValue());
        } else {
            variableList.push_back(new Variable(name, ref->getValue()));
        }
        printVariable(name);
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Creates a constant (only if name is valid and unused)
void VariableListManager::createConstant(const std::string& name, const std::string& value) {
    if (!isValidName(name)) {
        std::cout << "Invalid variable name. ";
        if (name == "const")
            std::cout << "\"const\" is a reserved keyword." << std::endl;
        else
            std::cout << "Cannot start with a digit." << std::endl;
        return;
    }

    if (findVariable(name)) {
        std::cout << "Invalid assignment. Cannot assign new value to a constant." << std::endl;
        return;
    }

    int num;
    std::stringstream ss(value);
    if (ss >> num && ss.eof()) {
        variableList.push_back(new Constant(name, num));
        printVariable(name);
        return;
    }

    Variable* ref = findVariable(value);
    if (ref) {
        variableList.push_back(new Constant(name, ref->getValue()));
        printVariable(name);
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Prints a single variable or constant value
void VariableListManager::printVariable(const std::string& name) {
    Variable* var = findVariable(name);
    if (var && var->defined()) {
        std::cout << var->getName() << "(" << var->getValue() << ")";
        if (var->isConstant())
            std::cout << " const";
        std::cout << std::endl;
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Prints all variables/constants in list
void VariableListManager::printAll() {
    for (auto var : variableList) {
        std::cout << var->getName() << "(" << var->getValue() << ")";
        if (var->isConstant())
            std::cout << " const";
        std::cout << std::endl;
    }
    std::cout << "Number of variables/constants: " << variableList.size() << std::endl;
}