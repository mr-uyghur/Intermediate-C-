//Author: Ali Halmamat
//De Anza College
//CIS 22B Spring 2025 
#include "VariableListManager.h"
#include <iostream>
#include <sstream>

int main() {
    VariableListManager manager;
    std::string input;

    std::cout << "Please enter variable assignment, variable name only or list or exit:" << std::endl;

    while (true) {
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if (input == "list") {
            manager.printAll(); // Show all variables/constants
        } else if (input.find("const ") == 0) {
            // Parse: const NAME = VALUE
            std::stringstream ss(input);
            std::string constKeyword, name, eq, value;
            ss >> constKeyword >> name >> eq >> value;
            manager.createConstant(name, value);
        } else if (input.find('=') != std::string::npos) {
            // Parse: NAME = VALUE
            std::stringstream ss(input);
            std::string name, eq, value;
            ss >> name >> eq >> value;
            manager.assignVariable(name, value);
        } else {
            manager.printVariable(input); // Lookup
        }
    }

    return 0;
}
