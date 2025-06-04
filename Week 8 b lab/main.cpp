// Given the definitions of main(), Read() and Write(), complete main.cpp by implementing the following member functions:

// template<typename TheType> vector<TheType> GetStatistics(const vector<TheType>& list)

// Take a vector template as a parameter
// Store the minimum, median, and maximum values of the vector parameter into a new vector
// Return the new vector
// template<typename TheType> void Run(vector<TheType>& list)

// Take a vector template as a parameter
// Call Read() with the vector parameter as an argument. Read() stores 5 input values into the vector parameter
// Sort the vector parameter
// Call Write() to output the sorted vector
// Output a new line
// Call GetStatistics() with the sorted vector as an argument. GetStatistics() returns a vector containing the minimum, median, and the maximum values of the sorted vector
// Call Write() to output the vector returned by GetStatistics()
// Output a new line
// Note: vector.size() returns a long unsigned int, not an int.

// Hint: Use the built-in sort function to sort a vector.

// Ex: If the input is:

// 1 3 5 9 7
// 2.2 3.3 1.1 4.4 5.5
// one two three four five
// the output is:

// 1 3 5 7 9
// 1 5 9

// 1.1 2.2 3.3 4.4 5.5
// 1.1 3.3 5.5

// five four one three two
// five one two

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // to use sort()
using namespace std;

const int NUM_VALUES = 5;

// Input NUM_VALUES of TheType into the vector parameter
template<typename TheType> void Read(vector<TheType>& list) {
   for (int j = 0; j < NUM_VALUES; ++j) {
      cin >> list.at(j);
   }
}

// Output the elements of the vector parameter
template<typename TheType> void Write(const vector<TheType>& list) {
   long unsigned int j;
   for (j = 0; j < list.size(); ++j) {
      cout << list.at(j) << " ";
   }
}

// Return the min, median, and max of the vector parameter in a new vector
template<typename TheType> vector<TheType> GetStatistics(const vector<TheType>& list) {
   /* Type your code here. */
   vector<TheType> stats(3);
   stats.at(0) = list.front(); //min
   stats.at(1) = list.at(list.size() / 2); // Median (middle after sort)
   stats.at(2) = list.back(); // Max
   return stats;
   
}

// Read values into a vector, sort the vector, output the sorted vector,
// then output the min, median, and max of the sorted vector
template<typename TheType> void Run(vector<TheType>& list) {
   /* Type your code here. */
   Read(list);
   sort(list.begin(), list.end());
   Write(list);

    cout << endl;

   vector<TheType> stats = GetStatistics(list);
   Write(stats);
   cout << endl;
   
}

int main() {
   vector<int> integers(NUM_VALUES);
   Run(integers);
   cout << endl;

   vector<double> doubles(NUM_VALUES);
   Run(doubles);
   cout << endl;

   vector<string> strings(NUM_VALUES);
   Run(strings);

   return 0;
}
