#ifndef VARIABLELISTMANAGER_H
#define VARIABLELISTMANAGER_H

#include "Variable.h"
#include <vector>

//Author: Ali Halmamat
//Date: 5/28/2025
//De Anza CIS 21B 2025 Spring

// Manages a dynamic list of Variable pointers using std::vector
class VariableListManager {
private:
    std::vector<Variable*> variableList; // Stores dynamically allocated Variable objects

public:
    // Destructor to free memory
    ~VariableListManager();

    // Finds a variable by name 
    Variable* findVariable(const std::string& name);

    // Handles assignment: name = value 
    void assignVariable(const std::string& name, const std::string& value);

    // Prints a single variable value or "Undefined"
    void printVariable(const std::string& name);

    // Prints all variables in the list
    void printAll();

    // Validates variable name 
    bool isValidName(const std::string& name) const;
};

#endif
