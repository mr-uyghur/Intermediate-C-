//Ali Halmamat
// CIS 22B De Anza College
// 5/7/2025
#include <iostream>
using namespace std;

// Function checks:
// - if first 3 elements are the same as last 3
// - if first 3 elements are "special": all same OR consecutive increasing
bool checkFirstLastThree(int* numList, int size, bool &special) {
    bool same = false; // default return value
    special = false;   // default special flag

    if (size < 3) {
        return same; // not enough elements
    }

    // Pointers to first three and last three
    int* first = numList;
    int* last = numList + size - 3;

    // Check if first three and last three elements are the same
    if (*(first)     == *(last) &&
        *(first + 1) == *(last + 1) &&
        *(first + 2) == *(last + 2)) {
        same = true;
    }

    // Check if first three elements are all the same
    if (*(first) == *(first + 1) && *(first + 1) == *(first + 2)) {
        special = true;
    }
    // Check if they are incrementing by 1
    else if ((*(first + 1) == *(first) + 1) &&
             (*(first + 2) == *(first + 1) + 1)) {
        special = true;
    }

    return same;
}

// Test the function
int main() {
    int numList0[] = {10};
    int numList1[] = {10, 20};
    int numList2[] = {10, 20, 30};
    int numList3[] = {10, 10, 10};
    int numList4[] = {10, 11, 12};
    int numList5[] = {10, 10, 10, 10};
    int numList6[] = {10, 10, 10, 10, 10};
    int numList7[] = {10, 20, 30, 10, 20, 30};
    int numList8[] = {10, 20, 30, 40, 10, 20, 30};
    int numList9[] = {10, 11, 12, 13, 10, 11, 12};

    int* testLists[] = {numList0, numList1, numList2, numList3, numList4,
                        numList5, numList6, numList7, numList8, numList9};

    int sizes[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7};

    for (int i = 0; i < 10; ++i) {
        bool special = false;
        bool result = checkFirstLastThree(testLists[i], sizes[i], special);
        cout << "List " << i << ": Same = " << (result ? "true" : "false")
             << ", Special = " << (special ? "true" : "false") << endl;
    }

    return 0;
}



