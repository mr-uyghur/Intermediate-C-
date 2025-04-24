//Ali Halmamat
// CIS 22B
// 2025-04-23
#include <iostream>
using namespace std;

// Question #1:
int readSecretKey(int &numTries) {
    int key, input, tries = 1;

    // Ask user to enter the key
    cout << "Please enter the key: ";
    cin >> key;

    // Ask user to re-enter the key for verification
    cout << "Please re-enter the key: ";
    cin >> input;

    // Allow up to 3 tries to match the key
    while (input != key && tries < 3) {
        cout << "Unmatched." << endl;
        tries++;
        cout << "Please re-enter the key: ";
        cin >> input;
    }

    // Update the number of tries
    numTries = tries;

    // Return the key if matched, otherwise return 0
    if (input == key)
        return key;
    else
        return 0;
}

// Question #2: 
int countScores(int count, bool &isPassing) {
    int score;
    int total = 0;
    int minScore = 0, maxScore = 0;
    int moreThan50 = 0;
    int i = 0;

    // Read scores one by one
    while (i < count) {
        cin >> score;

        // On first score, initialize min and max
        if (i == 0) {
            minScore = score;
            maxScore = score;
        } else {
            // Update min and max if needed
            if (score < minScore) minScore = score;
            if (score > maxScore) maxScore = score;
        }

        // Add score to total
        total += score;

        // Count scores greater than 50
        if (score > 50) moreThan50++;

        i++;
    }

    // Determine if the user passed (half or more scores > 50)
    isPassing = (moreThan50 >= (count + 1) / 2); // +1 handles odd number rounding

    // Return total minus the smallest and largest score
    return total - minScore - maxScore;
}

// Main function to test both features
int main() {
    int tries, key;

    // Test readSecretKey function
    key = readSecretKey(tries);
    cout << "Key: " << key << endl;
    cout << "Number of tries: " << tries << endl;

    // Test countScores function
    int count;
    cout << "Enter how many scores: ";
    cin >> count;

    cout << "Please enter the scores: ";
    bool passing;
    int result = countScores(count, passing);
    cout << "Total scores: " << result << endl;
    cout << "Passing: " << (passing ? "true" : "false") << endl;

    return 0;
}