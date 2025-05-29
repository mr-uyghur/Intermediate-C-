#include "VariableListManager.h"
#include <iostream>
#include <sstream>

int main() {
    VariableListManager manager;     // Creates the manager that holds all variables
    std::string input;

    std::cout << "Please enter variable assignment, variable name only or list or exit:" << std::endl;

    // Keeps looping until user enters "exit"
    while (true) {
        std::getline(std::cin, input);  // Get entire input line

        if (input == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if (input == "list") {
            manager.printAll(); // Print all variables
        } else if (input.find('=') != std::string::npos) {
            // Handle variable assignment like: count = 10
            std::stringstream ss(input);
            std::string name, eq, value;
            ss >> name >> eq >> value;

            if (eq == "=")
                manager.assignVariable(name, value);
        } else {
            // Treat it as a variable lookup
            manager.printVariable(input);
        }
    }

    return 0;
}
