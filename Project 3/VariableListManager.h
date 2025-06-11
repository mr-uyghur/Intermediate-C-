//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#ifndef VARIABLELISTMANAGER_H
#define VARIABLELISTMANAGER_H

#include "Variable.h"
#include "Constant.h"
#include <vector>

// Manages list of Variable pointers (both Variable and Constant types)
class VariableListManager {
private:
    std::vector<Variable*> variableList;

public:
    ~VariableListManager(); // free heap memory

    void assignVariable(const std::string& name, const std::string& value);
    void createConstant(const std::string& name, const std::string& value);
    void printVariable(const std::string& name);
    void printAll();

    Variable* findVariable(const std::string& name);
    bool isValidName(const std::string& name) const;
};

#endif