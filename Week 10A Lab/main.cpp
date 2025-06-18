// The given program reads a list of single-word first names and ages (ending with -1), and outputs that list with the age incremented. The program fails and throws an exception if the second input on a line is a string rather than an int. At FIXME in the code, add a try/catch statement to catch ios_base::failure, and output 0 for the age.

// Ex: If the input is:

// Lee 18
// Lua 21
// Mary Beth 19
// Stu 33
// -1
// then the output is:

// Lee 19
// Lua 22
// Mary 0
// Stu 34
// Note: Insert the following code in the catch block to clear the failbit and cin buffer so a new input can be read correctly:

// // Clear failbit to be able to use cin again
// cin.clear();
// // Throw away the rest of the failed input line from cin buffer
// string garbage;
// getline(cin, garbage);

#include <string>
#include <iostream>

using namespace std;

int main()
{
    string inputName;
    int age;
    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    cin >> inputName;
    while (inputName != "-1")
    {
        // FIXME: The following line will throw an ios_base::failure.
        //        Insert a try/catch statement to catch the exception.
        //        Clear cin's failbit to put cin in a useable state.
        bool validInput = true;
        try
        {
            cin >> age;
        }
        catch (ios_base::failure &e)
        {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            age = 0;
            validInput = false;
        }
        cout << inputName << " " << (validInput ? (age + 1) : age) << endl;

        cin >> inputName;
    }

    return 0;
}