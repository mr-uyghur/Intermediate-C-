#ifndef VARIABLELISTMANAGER_H
#define VARIABLELISTMANAGER_H

#include "Variable.h"
#include <vector>

// Manages a dynamic list of Variable pointers using std::vector
class VariableListManager {
private:
    std::vector<Variable*> variableList; // Stores dynamically allocated Variable objects

public:
    // Destructor to free memory
    ~VariableListManager();

    // Finds a variable by name (returns pointer or nullptr)
    Variable* findVariable(const std::string& name);

    // Handles assignment: name = value (value can be number or variable name)
    void assignVariable(const std::string& name, const std::string& value);

    // Prints a single variable value or "Undefined"
    void printVariable(const std::string& name);

    // Prints all variables in the list
    void printAll();

    // Validates variable name (must not start with digit)
    bool isValidName(const std::string& name) const;
};

#endif
