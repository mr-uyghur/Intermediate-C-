#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

// Represents a single variable with a name and a value
class Variable {
private:
    std::string name;   // Name of the variable (e.g., "count", "total")
    int value;          // Integer value assigned to the variable
    bool isDefined;     // True if a value has been assigned

public:
    // Constructor that takes name and value — no default constructor allowed
    Variable(const std::string& varName, int val);

    // Getters
    std::string getName() const;   // Returns the name of the variable
    int getValue() const;          // Returns the value
    bool defined() const;          // Returns true if the variable is defined

    // Setter
    void setValue(int val);        // Assigns a new value to the variable
};

#endif
