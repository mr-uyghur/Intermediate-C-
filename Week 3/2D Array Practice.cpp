// #CIS 2B De Anza College
// #Author: Ali Halmamat
// #Date: 2025-04-30

#include <iostream>
using namespace std;

// Function to calculate student scores statistics
// Returns number of students with at least 3 passing scores
// Also returns count of 100s and number of students with at least one 0 via reference parameters
int calcStudentScores(const int scores[][4], int numStudents, int& count100s, int& countZeroStudents) {
    int count3Passing = 0;
    count100s = 0;
    countZeroStudents = 0;

    for (int i = 0; i < numStudents; i++) {
        int passingCount = 0;
        bool hasZero = false;

        for (int j = 0; j < 4; j++) {
            if (scores[i][j] >= 50) {
                passingCount++;
            }
            if (scores[i][j] == 100) {
                count100s++;
            }
            if (scores[i][j] == 0) {
                hasZero = true;
            }
        }

        if (passingCount >= 3) {
            count3Passing++;
        }
        if (hasZero) {
            countZeroStudents++;
        }
    }

    return count3Passing;
}

// Function to report grades statistics
// Returns number of students with at least 2 passing tests
// Also returns counts of passing per test via reference parameter
int reportOutGrades(const char grades[][4], int numStudents, int passingCounts[]) {
    int count2Passing = 0;

    // Initialize passing counts array
    for (int i = 0; i < 4; i++) {
        passingCounts[i] = 0;
    }
    //use nested loop to iterate through the 2D array
    for (int i = 0; i < numStudents; i++) {
        int passingCount = 0;

        for (int j = 0; j < 4; j++) {
            if (grades[i][j] == 'P') {
                passingCount++;
                passingCounts[j]++;
            }
        }

        if (passingCount >= 2) {
            count2Passing++;
        }
    }

    return count2Passing;
}

// Test function for calcStudentScores
void testCalcStudentScores() {
    cout << "Testing calcStudentScores function:\n\n";

    // Test case 1
    int stuScoreList1[][4] = { {100, 100, 100, 100} };
    int count100s, countZeroStudents;
    int count3Passing = calcStudentScores(stuScoreList1, 1, count100s, countZeroStudents);
    cout << "Test 1: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 2
    int stuScoreList2[][4] = { {0, 0, 0, 0} };
    count3Passing = calcStudentScores(stuScoreList2, 1, count100s, countZeroStudents);
    cout << "Test 2: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 3
    int stuScoreList3[][4] = { {100, 0, 50, 50} };
    count3Passing = calcStudentScores(stuScoreList3, 1, count100s, countZeroStudents);
    cout << "Test 3: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 4
    int stuScoreList4[][4] = { {50, 0, 50, 0} };
    count3Passing = calcStudentScores(stuScoreList4, 1, count100s, countZeroStudents);
    cout << "Test 4: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 5
    int stuScoreList5[][4] = { {100, 100, 100, 100},
                               {100, 0, 0, 0} };
    count3Passing = calcStudentScores(stuScoreList5, 2, count100s, countZeroStudents);
    cout << "Test 5: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 6
    int stuScoreList6[][4] = { {30, 50, 70, 90},
                               {100, 100, 100, 100},
                               {100, 20, 50, 0},
                               {0, 100, 40, 60},
                               {100, 100, 100, 100},
                               {10, 50, 0, 0} };
    count3Passing = calcStudentScores(stuScoreList6, 6, count100s, countZeroStudents);
    cout << "Test 6: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;

    // Test case 7
    int stuScoreList7[][4] = { {30, 50, 70, 0},
                               {100, 20, 50, 0},
                               {100, 100, 0, 0} };
    count3Passing = calcStudentScores(stuScoreList7, 3, count100s, countZeroStudents);
    cout << "Test 7: At least one zero: " << countZeroStudents 
         << "  Count of 100s: " << count100s 
         << "  At least 3 passing: " << count3Passing << endl;
}

// Test function for reportOutGrades
void testReportOutGrades() {
    cout << "\nTesting reportOutGrades function:\n\n";

    // Test case 1
    char testList1[][4] = { {'P', 'N', 'P', 'N'} };
    int passingCounts[4];
    int count2Passing = reportOutGrades(testList1, 1, passingCounts);
    cout << "Test 1: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;

    // Test case 2
    char testList2[][4] = { {'P', 'P', 'P', 'P'} };
    count2Passing = reportOutGrades(testList2, 1, passingCounts);
    cout << "Test 2: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;

    // Test case 3
    char testList3[][4] = { {'N', 'N', 'N', 'N'} };
    count2Passing = reportOutGrades(testList3, 1, passingCounts);
    cout << "Test 3: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;

    // Test case 4
    char testList4[][4] = { {'N', 'P', 'N', 'P'}, 
                            {'N', 'N', 'P', 'P'} };
    count2Passing = reportOutGrades(testList4, 2, passingCounts);
    cout << "Test 4: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;

    // Test case 5
    char testList5[][4] = { {'P', 'P', 'P', 'P'},
                            {'P', 'N', 'P', 'N'},
                            {'P', 'P', 'P', 'P'},
                            {'N', 'N', 'N', 'N'} };
    count2Passing = reportOutGrades(testList5, 4, passingCounts);
    cout << "Test 5: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;

    // Test case 6
    char testList6[][4] = { {'P', 'N', 'N', 'P'},
                            {'P', 'N', 'N', 'P'},
                            {'P', 'P', 'N', 'N'},
                            {'N', 'N', 'P', 'P'},
                            {'P', 'N', 'N', 'P'} };
    count2Passing = reportOutGrades(testList6, 5, passingCounts);
    cout << "Test 6: At least two passes: " << count2Passing 
         << "  Passing count per test: ";
    for (int i = 0; i < 4; i++) {
        cout << passingCounts[i] << "   ";
    }
    cout << endl;
}

int main() {
    testCalcStudentScores();
    testReportOutGrades();
    return 0;
}


