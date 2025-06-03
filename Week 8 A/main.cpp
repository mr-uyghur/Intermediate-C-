// Define a generic function called CheckOrder() that checks if four items are in ascending, neither, or descending order. The function should return -1 if the items are in ascending order, 0 if the items are unordered, and 1 if the items are in descending order.

// The program reads four items from input and outputs if the items are ordered. The items can be different types, including integers, strings, characters, or doubles.

// Ex. If the input is:

// bat hat mat sat
// 63.2 96.5 100.1 123.5
// the output is:

// Order: -1
// Order: -1

#include <string>
#include <iostream>

using namespace std;

// TODO: Define a generic method called CheckOrder() that
//       takes in four variables of generic type as arguments.
//       The return type of the method is integer

   // Check the order of the input: return -1 for ascending,
   // 0 for neither, 1 for descending
   template<typename T>
    int CheckOrder (T a, T b, T c, T d){
        if (a <= b && b <= c && c <= d) {
      return -1; // Ascending
   }
        else if (a >= b && b >= c && c >= d) {
      return 1; // Descending
   }
        else {
      return 0; // Neither
   }
    }

int main() {
   // Read in four strings
   string stringArg1, stringArg2, stringArg3, stringArg4;
   cin >> stringArg1;
   cin >> stringArg2;
   cin >> stringArg3;
   cin >> stringArg4;
   // Check order of four strings
   cout << "Order: " << CheckOrder(stringArg1, stringArg2, stringArg3, stringArg4) << endl;

   // Read in four doubles
   double doubleArg1, doubleArg2, doubleArg3, doubleArg4;
   cin >> doubleArg1;
   cin >> doubleArg2;
   cin >> doubleArg3;
   cin >> doubleArg4;
   // Check order of four doubles
   cout << "Order: " << CheckOrder(doubleArg1, doubleArg2, doubleArg3, doubleArg4) << endl;
   
   return 0;
}