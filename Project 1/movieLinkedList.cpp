#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

//Ali Halmamat
//05/14/2025
//CIS 22B
//Meaning Full File Name: movieLinkedList.cpp
//Took off 2 points from my last assignment Even though "Meaningful file name" was NOT listed as a requirement.
// I’ve named this file meaningfully as part of my effort to improve based on feedback from the previous assignment, 
// where points were deducted for file naming even though it wasn’t explicitly required. I appreciate the guidance.
//Please be more specific with the requirements if you're going to take off points for something that wasn't included there.

using namespace std;

// Define the Movie structure for the linked list
struct Movie {
    string title;
    int year;
    int rating;
    Movie* next; // pointer to the next movie
};

// Pointer to the start of the list
Movie* head = nullptr;

// Helper function to convert strings to lowercase for case-insensitive comparisons
string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Function to add a new movie to the front of the list
void addMovie() {
    Movie* newMovie = new Movie;

    // Get movie title from user
    cout << "Enter a movie's name: ";
    getline(cin >> ws, newMovie->title); // ws clears leading whitespace

    // Get and validate year viewed
    cout << "Enter the year you saw " << newMovie->title << " [like 2016]: ";
    while (!(cin >> newMovie->year) || newMovie->year < 1800 || newMovie->year > 2100) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid year. Try again: ";
    }

    // Get and validate rating
    cout << "Enter your rating for " << newMovie->title << " [1, 2, 3, 4, 5]: ";
    while (!(cin >> newMovie->rating) || newMovie->rating < 1 || newMovie->rating > 5) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid rating. Try again: ";
    }

    // Insert the new movie at the front of the list
    newMovie->next = head;
    head = newMovie;
    cout << endl;
}

// Function to print all movies in a formatted list
void listMovies() {
    Movie* curr = head;
    int index = 1;

    // Print table headers
    cout << "#  Title                           Viewed  Rating\n";
    cout << "-- ------------------------------- ------- ------\n";

    // Traverse and print each movie node
    while (curr) {
        cout << index++ << "  ";
        cout.width(30);
        cout.setf(ios::left);
        cout << curr->title;
        cout.unsetf(ios::left);
        cout << " " << curr->year << "    " << curr->rating << endl;
        curr = curr->next;
    }
    cout << endl;
}

// Function to count and return the number of nodes in the list
int getListSize() {
    int count = 0;
    Movie* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Function to remove a movie by its sequence number
void removeMovie() {
    int size = getListSize();
    if (size == 0) {
        cout << "No movies to remove.\n\n";
        return;
    }

    listMovies(); // Show current list
    cout << "...which movie to remove (1-" << size << ")? ";
    int choice;
    cin >> choice;

    // Check if the input is within valid range
    if (choice < 1 || choice > size) {
        cout << "Invalid choice.\n\n";
        return;
    }

    Movie* curr = head;
    Movie* prev = nullptr;

    // Traverse to the selected node
    for (int i = 1; i < choice; ++i) {
        prev = curr;
        curr = curr->next;
    }

    // Remove the node from the list
    if (!prev) head = curr->next;      // If removing head
    else prev->next = curr->next;      // Otherwise bypass the node

    delete curr; // Free memory
    cout << "Movie removed.\n\n";
}

// Function to update a movie's year and rating
void updateMovie() {
    int size = getListSize();
    if (size == 0) {
        cout << "No movies to update.\n\n";
        return;
    }

    listMovies(); // Show current list
    cout << "...which movie to update (1-" << size << ")? ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > size) {
        cout << "Invalid choice.\n\n";
        return;
    }

    // Traverse to the selected node
    Movie* curr = head;
    for (int i = 1; i < choice; ++i) {
        curr = curr->next;
    }

    // Prompt for and update year
    cout << "Enter new year viewed: ";
    while (!(cin >> curr->year) || curr->year < 1800 || curr->year > 2100) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid year. Try again: ";
    }

    // Prompt for and update rating
    cout << "Enter new rating [1-5]: ";
    while (!(cin >> curr->rating) || curr->rating < 1 || curr->rating > 5) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid rating. Try again: ";
    }

    cout << "Movie updated.\n\n";
}

// Sort movies alphabetically by title using bubble sort logic
void sortByTitle() {
    if (!head || !head->next) return; // Nothing to sort if 0 or 1 node

    for (Movie* i = head; i; i = i->next) {
        for (Movie* j = i->next; j; j = j->next) {
            // Compare lowercase titles for case-insensitive sorting
            if (toLower(j->title) < toLower(i->title)) {
                swap(i->title, j->title);
                swap(i->year, j->year);
                swap(i->rating, j->rating);
            }
        }
    }
    cout << "Movies sorted by title.\n\n";
}

// Sort movies by year viewed (ascending)
void sortByYear() {
    if (!head || !head->next) return;

    for (Movie* i = head; i; i = i->next) {
        for (Movie* j = i->next; j; j = j->next) {
            if (j->year < i->year) {
                swap(i->title, j->title);
                swap(i->year, j->year);
                swap(i->rating, j->rating);
            }
        }
    }
    cout << "Movies sorted by year viewed.\n\n";
}

// Sort movies by rating (ascending)
void sortByRating() {
    if (!head || !head->next) return;

    for (Movie* i = head; i; i = i->next) {
        for (Movie* j = i->next; j; j = j->next) {
            if (j->rating < i->rating) {
                swap(i->title, j->title);
                swap(i->year, j->year);
                swap(i->rating, j->rating);
            }
        }
    }
    cout << "Movies sorted by rating.\n\n";
}

// Delete all nodes and free memory
void cleanup() {
    while (head) {
        Movie* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main menu loop
int main() {
    char choice;

    do {
        // Show menu options
        cout << "MENU\n"
             << "A Add a movie\n"
             << "U Update a movie\n"
             << "E Remove a movie\n"
             << "L List all movies\n"
             << "T arrange by Title\n"
             << "V arrange by year Viewed\n"
             << "R arrange by Rating\n"
             << "Q Quit\n"
             << "...your choice: ";
        cin >> choice;
        choice = tolower(choice); // Case-insensitive input

        // Call appropriate function
        switch (choice) {
            case 'a': addMovie(); break;
            case 'u': updateMovie(); break;
            case 'e': removeMovie(); break;
            case 'l': listMovies(); break;
            case 't': sortByTitle(); break;
            case 'v': sortByYear(); break;
            case 'r': sortByRating(); break;
            case 'q': cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n\n";
        }

    } while (choice != 'q'); // Repeat until user chooses to quit

    cleanup(); // Free all memory before exiting
    return 0;
}
