#include <iostream>
#include "User.h"

int User::nextID = 0;

User::User(string n) : name(n), userID(nextID++) {}

string User::getName() const { return name; }
int User::getUserID() const { return userID; }

// =============================================================== //
// Function to add a book to the borrowed book list in the library //
// =============================================================== //
void User::borrowBook(Book* book) 
{
    borrowedBooks.push_back(book); 
    incrementBorrowedBookCount(); 
}

// ======================================== //
// Function to return a book to the library //
// ======================================== //
void User::returnBook(Book* book) 
{
    // Logic for returning books: remove the book from borrowedBooks
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) 
    {
        if (*it == book) 
        {
            borrowedBooks.erase(it);  // Remove the book from the list
            decrementBorrowedBookCount();  // Decrement borrowed count
            return;
        }
    }
    cout << "Book not found in borrowed list." << endl;  // If the book was not found
}

// ================================================================ //
// Function to increment the count of borrowed books to the library //
// ================================================================ //
void User::incrementBorrowedBookCount() 
{
    borrowedBooks.push_back(nullptr);
}

// ================================================================ //
// Function to decrement the count of borrowed books to the library //
// ================================================================ //
void User::decrementBorrowedBookCount() 
{
    if (!borrowedBooks.empty()) 
    {
        borrowedBooks.pop_back();  // Remove the last borrowed book
    }
    else 
    {
        cout << "No borrowed books to return!" << endl;  // Error message if no borrowed books
    }
}
