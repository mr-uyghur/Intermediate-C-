#include <iostream>
#include <cstring>
using namespace std;

// Return a newly allocated copy of original
// with the first occurrence of each vowel capitalized
char* CapVowels(char* original) {
   /*
      A new string must be allocated because 
      a statically declared array (char result[50]) cannot be returned.
   */
   
   /* Type your code here. */
   //create a chat var with the same length as the original 
   //+1 to the length for null termination
   char* result = new char[strlen(original) + 1];

   //copy the characters in to result var using while loop
   int i = 0;
   while(original[i] != '\0'){
    result[i] = original[i];
    i++;
   }
   result[i] = '\0';

   //create an array to keep track of the vowels
   char vowels[] = {'a','e','i','o','u'};
   char upperVowels [] = {'A','E','I','O','U'};
   bool foundVowels[5] = {false};

   //loop through each characters in the string til we find vowels
   for(int i = 0; result[i] != '\0'; i++){
    for(int v = 0; v < 5; v++){
        if(result[i] == vowels[v] && !foundVowels[v]){
            result[i] = upperVowels[v];
            foundVowels[v] = true;
            break;
        }
    }
   }

   return result;
   
}

int main() {

   char userCaption[50];
   char* resultStr;
   cin >> userCaption;

   resultStr = CapVowels(userCaption);

   printf("Original: %s\n", userCaption);
   printf("Modified: %s\n", resultStr);
   
   // Always free dynamically allocated memory when no longer needed
   delete(resultStr);

   return 0;
}
