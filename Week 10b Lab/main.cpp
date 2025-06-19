// Write a recursive function called ReverseString() that takes in a string as a parameter and returns the string in reversed order. The main function is provided to read a string from the user and call the ReverseString() function.

// Ex: If the input of the program is:

// Hello
// the ReverseString() function returns and the program outputs:

// Reverse of "Hello" is "olleH".
// Ex: If the input of the program is:

// Hello, world!
// the ReverseString() function returns and the program outputs:

// Reverse of "Hello, world!" is "!dlrow ,olleH".
// Hint: Move the first character to the end of the returning string and pass the remaining sub-string to the next ReverseString() function call.

#include <iostream>
using namespace std;

/* TODO: Write recursive ReverseString() function here. */

string ReverseString(const string &str)
{
    if (str.empty())
    {
        return "";
    }

    return ReverseString(str.substr(1)) + str[0];
}

int main()
{
    string input, result;

    getline(cin, input);
    result = ReverseString(input);
    cout << "Reverse of \"" << input << "\" is \"" << result << "\"." << endl;

    return 0;
}
