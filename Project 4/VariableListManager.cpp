//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#include "VariableListManager.h"
#include "BadVarException.h"
#include <iostream>
#include <sstream>
#include <cctype>

// Destructor: deletes all allocated Variable/Constant objects
VariableListManager::~VariableListManager() {
    for (auto var : variableList)
        delete var;
}

// Returns false if name is invalid (starts with digit or is "const")
bool VariableListManager::isValidName(const std::string& name) const {
    if (name == "const")
        return false;
    return !isdigit(name[0]);
}

// Finds a variable or constant by name
Variable* VariableListManager::findVariable(const std::string& name) {
    for (auto var : variableList)
        if (var->getName() == name)
            return var;
    return nullptr;
}

// Assigns or updates variable; handles numeric or reference values
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
    int num;
    std::stringstream ss(value);

    // Handle direct integer assignment
    if (ss >> num && ss.eof()) {
        try {
            if (existing)
                existing->setValue(num);
            else
                variableList.push_back(new Variable(name, num));
            printVariable(name);
        } catch (const BadVarException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        return;
    }

    // Handle variable-to-variable reference
    Variable* ref = findVariable(value);
    if (ref) {
        try {
            if (existing)
                existing->setValue(ref->getValue());
            else
                variableList.push_back(new Variable(name, ref->getValue()));
            printVariable(name);
        } catch (const BadVarException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Creates a new constant; throws exception on bad input
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
        try {
            variableList.push_back(new Constant(name, num));
            printVariable(name);
        } catch (const BadVarException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        return;
    }

    Variable* ref = findVariable(value);
    if (ref) {
        try {
            variableList.push_back(new Constant(name, ref->getValue()));
            printVariable(name);
        } catch (const BadVarException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Undefined" << std::endl;
    }
}

// Prints a single variable or constant
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

// Prints all stored variables/constants
void VariableListManager::printAll() {
    for (auto var : variableList) {
        std::cout << var->getName() << "(" << var->getValue() << ")";
        if (var->isConstant())
            std::cout << " const";
        std::cout << std::endl;
    }
    std::cout << "Number of variables/constants: " << variableList.size() << std::endl;
}
