// An initial dataset of temperatures is read throughout the week; however, the dataset contains outlier data (not in the range 0-100 inclusive). The provided program declares pointers for the original and new arrays and outputs the contents of the arrays. Complete main() to perform the following tasks:

// Find the size of the new array without outliers.
// Assign filteredValues with a new integer array with size newSize.
// Store the filtered values in the new array.
// Delete the original array and assign originalValues with nullptr.
// Ex: If the input is:

// 10 100 -10 80 500 50 0
// then the output is:

// Old array pointer: 0
// New array: 10 100 80 50 0


#include <iostream>
using namespace std;

int main() {
   const int size = 7;
   int newSize = 0;
   int* originalValues = new int[size];
   int* filteredValues;
   int i;

   for (i = 0; i < size; ++i) {
      cin >> originalValues[i];
   }

   // TODO: Type your code here.
   //use a for loop to count valid entries (0-100 only)
   for (i=0; i < size; ++i){
    if(originalValues[i] >= 0 && originalValues[i] <=100){
        ++newSize;
    }
   }

   filteredValues = new int[newSize];

   //store the filtered values into the new array
   int j = 0;
   for(i=0; i < size; ++i){
    if(originalValues[i] >=0 && originalValues[i] <= 100){
        filteredValues[j] = originalValues[i];
        ++j;
    }
   }

   delete[] originalValues;
   originalValues = nullptr;

   cout << "Old array pointer: " << originalValues << endl;

   cout << "New array: ";
   for (i = 0; i < newSize; ++i) {
      cout << filteredValues[i] << " ";
   }
   cout << endl;

   return 0;
}
