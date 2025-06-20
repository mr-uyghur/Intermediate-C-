//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef VARIABLELISTMANAGER_H
#define VARIABLELISTMANAGER_H

#include "Variable.h"
#include "Constant.h"
#include <vector>

// Class that manages a collection of variables and constants
class VariableListManager {
private:
    std::vector<Variable*> variableList;  // Polymorphic list

public:
    ~VariableListManager();               // Clean up dynamic memory

    void assignVariable(const std::string& name, const std::string& value);
    void createConstant(const std::string& name, const std::string& value);
    void printVariable(const std::string& name);
    void printAll();

    Variable* findVariable(const std::string& name);
    bool isValidName(const std::string& name) const;
};

#endif
