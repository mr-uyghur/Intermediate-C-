//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 

#include "VariableListManager.h"
#include <iostream>
#include <sstream>

// Entry point of the program.
// Handles input commands and delegates to VariableListManager.
int main() {
    VariableListManager manager; // Manages variables and constants
    std::string input;

    std::cout << "Please enter variable assignment, variable name only or list or exit:" << std::endl;

    while (true) {
        std::getline(std::cin, input); // Read full input line

        if (input == "exit") {
            std::cout << "Exiting..." << std::endl;
            break; // Exit loop and terminate program
        } else if (input == "list") {
            manager.printAll(); // List all variables and constants
        } else if (input.find("const ") == 0) {
            // Handle constant creation: const NAME = VALUE
            std::stringstream ss(input);
            std::string constKeyword, name, eq, value;
            ss >> constKeyword >> name >> eq >> value;
            manager.createConstant(name, value);
        } else if (input.find('=') != std::string::npos) {
            // Handle variable assignment: NAME = VALUE
            std::stringstream ss(input);
            std::string name, eq, value;
            ss >> name >> eq >> value;
            manager.assignVariable(name, value);
        } else {
            // Lookup and print variable or constant value
            manager.printVariable(input);
        }
    }

    return 0;
}