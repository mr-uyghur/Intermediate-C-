#include <iostream>

int PrintMyName(int count, int n) {
    int sum = count + n;
    for (int i = 1; i <= count; i++) {
        if (i == n) {
            std::cout << "Hello 22B" << std::endl;
        } else {
            std::cout << "Ali Halmamat" << std::endl;
        }
    }
    return sum;
}

int main() {
    int sum = PrintMyName(7, 3);  //I don't think these values were specified in the instructions?
    
    std::cout << "\nQuarter and year you took CIS 22A: Winter 2023 De Anza" << std::endl;
    std::cout << "Format you took it: sync." << std::endl;
    std::cout << "online" << std::endl;
    
    return 0;
} 