//Ali Halmamat
//CIS22B
//04/23/2025
#include <iostream>
using namespace std;

// Function to check if a character is a valid hexadecimal digit
bool isHexaChar(char ch) {
    return ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F'));
}

// Question #1: Analyze array properties in one loop
bool getArrayInfo(const int arr[], int size, bool &isAscending, bool &isBounded, int &largerValue) {
    isAscending = true;  // Assume true unless proven false
    isBounded = true;

    int lower;
    int upper;

    // Set lower and upper bounds based on first and last elements
    if (arr[0] < arr[size - 1]) {
        lower = arr[0];
        upper = arr[size - 1];
    } else {
        lower = arr[size - 1];
        upper = arr[0];
    }

    largerValue = upper;

    int i = 1;
    while (i < size) {
        // Check ascending order
        if (arr[i] < arr[i - 1]) {
            isAscending = false;
        }

        // Check bounded condition
        if (arr[i] < lower || arr[i] > upper) {
            isBounded = false;
        }

        i = i + 1;
    }

    return true; // Just to complete function
}

// Question #2: Check if C-string is valid hexadecimal
bool isHexadecimal(const char str[], bool &hasPrefix) {
    hasPrefix = false;
    bool isValid = true;
    int i = 0;

    // Check for empty string
    if (str[0] == '\0') {
        return false;
    }

    // Check for "0x" or "0X" prefix
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        hasPrefix = true;
        i = 2;

        // If nothing after prefix, invalid
        if (str[i] == '\0') {
            return false;
        }
    }

    // Check each character
    while (str[i] != '\0') {
        if (!isHexaChar(str[i])) {
            isValid = false;
        }
        i = i + 1;
    }

    return isValid;
}

// Main function to test everything
int main() {
    // Testing getArrayInfo
    int arr1[] = {10, 30, 20, 40};
    bool asc1;
    bool bound1;
    int big1;
    getArrayInfo(arr1, 4, asc1, bound1, big1);

    cout << "Test 1 - getArrayInfo" << endl;
    cout << "Ascending: " << asc1 << endl;
    cout << "Bounded: " << bound1 << endl;
    cout << "Larger value: " << big1 << endl;

    int arr2[] = {50, 20, 30, 40, 10};
    bool asc2;
    bool bound2;
    int big2;
    getArrayInfo(arr2, 5, asc2, bound2, big2);

    cout << "Test 2 - getArrayInfo" << endl;
    cout << "Ascending: " << asc2 << endl;
    cout << "Bounded: " << bound2 << endl;
    cout << "Larger value: " << big2 << endl;

    // Testing isHexadecimal
    char hex1[] = {'0', 'x', 'a', '\0'};
    bool prefix1;
    bool valid1 = isHexadecimal(hex1, prefix1);

    cout << "Test 1 - isHexadecimal" << endl;
    cout << "Valid: " << valid1 << endl;
    cout << "Has Prefix: " << prefix1 << endl;

    char hex2[] = {'1', 'x', 'a', '\0'};
    bool prefix2;
    bool valid2 = isHexadecimal(hex2, prefix2);

    cout << "Test 2 - isHexadecimal" << endl;
    cout << "Valid: " << valid2 << endl;
    cout << "Has Prefix: " << prefix2 << endl;

    char hex3[] = {'0', 'x', '\0'};
    bool prefix3;
    bool valid3 = isHexadecimal(hex3, prefix3);

    cout << "Test 3 - isHexadecimal" << endl;
    cout << "Valid: " << valid3 << endl;
    cout << "Has Prefix: " << prefix3 << endl;

    return 0;
}
