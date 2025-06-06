// Complete template<typename TheType> class Pair by defining the following methods:

// void Input()
// Read two values from input and initialize the data members with the values in the order in which they appear
// void Output()
// Output the Pair in the format "[firstVal, secondVal]"
// char CompareWith(Pair* otherPair)
// Return the character '<', '=', or '>' according to whether the Pair is less than, equal to, or greater than otherPair
// Precedence of comparisons is firstVal then secondVal
// char ShowComparison(Pair* otherPair)
// Compare with otherPair by calling CompareWith()
// Output the two Pairs separated by the character returned by CompareWith(). Hint: Output each Pair using Output()
// Note: For each type main() calls Input() twice to create two Pairs of that type.

// Ex: If the input for two Integer Pairs is:

// 4 6 3 5
// the first Pair is [4, 6], and the second Pair is [3, 5].

// Ex: If the input of the program is:

// 4 6 3 5
// 4.3 2.1 4.3 2.1
// one two three four
// the output is:

// [4, 6] > [3, 5]
// [4.3, 2.1] = [4.3, 2.1]
// [one, two] < [three, four]



#include <iostream>
#include <string>
using namespace std;

/*** Template class Pair ***/
template<typename TheType> class Pair {
   public:
      void Input();
      void Output();
      char CompareWith(Pair<TheType>* otherPair) ;
      void ShowComparison(Pair<TheType>* otherPair);

   private:
      TheType firstVal;
      TheType secondVal;
};

// Return '<', '=', or '>' according to whether the Pair is less than,
// equal to, or greater than the argument Pair
template<typename TheType>
char Pair<TheType>::CompareWith(Pair<TheType>* otherPair) {
   if (firstVal < otherPair->firstVal) {
      return '<';
   }
   else if (firstVal > otherPair->firstVal) {
      return '>';
   }
   else {
      if (secondVal < otherPair->secondVal) {
         return '<';
      }
      else if (secondVal > otherPair->secondVal) {
         return '>';
      }
      else {
         return '=';
      }
   }
}

// Input values into a pair
template<typename TheType>
void Pair<TheType>::Input() {
   cin >> firstVal >> secondVal;
}

// Output a Pair 
template<typename TheType>
void Pair<TheType>::Output() {
   cout << "[" << firstVal << ", " << secondVal << "]";
}

// Output both pairs with a comparison symbol in between
template<typename TheType>
void Pair<TheType>::ShowComparison(Pair<TheType>* otherPair) {
   Output();
   cout << " " << CompareWith(otherPair) << " ";
   otherPair->Output();
   cout << endl;
}
/*** End template class Pair ***/

int main() {
   Pair<int> intPair;
   Pair<int> intOtherPair;
   intPair.Input();
   intOtherPair.Input();
   intPair.ShowComparison(&intOtherPair);

   Pair<double> doublePair;
   Pair<double> doubleOtherPair;
   doublePair.Input();
   doubleOtherPair.Input();
   doublePair.ShowComparison(&doubleOtherPair);

   Pair<string> wordPair;
   Pair<string> wordOtherPair;
   wordPair.Input();
   wordOtherPair.Input();
   wordPair.ShowComparison(&wordOtherPair);

   return 0;
}
