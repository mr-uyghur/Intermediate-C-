// Author: Ali Halmamat
// De Anza College
// CIS 22B Spring 2025

#include "Variable.h"
#include "BadVarException.h"

// Constructor that validates name and value
Variable::Variable(const std::string &varName, int val)
{
    std::string trimmed = varName;
    // Remove leading and trailing spaces
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

    // Validate name and value
    if (trimmed.empty())
        throw BadVarException("Invalid variable name: Name cannot be empty or all spaces.");
    if (val < 0)
        throw BadVarException("Invalid variable value: Cannot be negative.");

    name = trimmed;
    value = val;
    isDefined = true;
}

std::string Variable::getName() const { return name; }

int Variable::getValue() const { return value; }

bool Variable::defined() const { return isDefined; }

// Sets or updates the value
void Variable::setValue(int val)
{
    value = val;
    isDefined = true;
}

// Default: Not a constant
bool Variable::isConstant() const
{
    return false;
}
