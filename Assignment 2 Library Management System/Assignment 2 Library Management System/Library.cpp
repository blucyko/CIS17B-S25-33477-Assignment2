#include "Library.h"
#include <iostream>

using namespace std;

Library* Library::instance = nullptr;

Library& Library::getInstance() 
{
    if (!instance) 
    {
        instance = new Library();
    }
    return *instance;
}

Library::~Library() 
{
    for (auto user : users) 
    {
        delete user;  // Prevent memory leaks
    }
    users.clear();

    delete instance;
    instance = nullptr;
}

// ===================================== //
// Function to add a book to the library //
// ===================================== //
void Library::addBook() 
{
    string title, author, isbn;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, isbn);

    books.push_back(Book(title, author, isbn));
    cout << "Book Added" << endl;
}

// ====================================== //
// Function to edit a book in the library //
// ====================================== //
void Library::editBook() 
{
    cout << "Enter the title of the book to edit: ";
    string title;
    cin.ignore();
    getline(cin, title);

    for (auto& book : books) {
        if (book.getTitle() == title) {
            cout << "Enter new title: ";
            string newTitle;
            getline(cin, newTitle);
            cout << "Enter new author: ";
            string newAuthor;
            getline(cin, newAuthor);
            cout << "Enter new ISBN: ";
            string newISBN;
            getline(cin, newISBN);

            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setISBN(newISBN);
            cout << "Book updated successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

// ======================================== //
// Function to remove a book in the library //
// ======================================== //
void Library::removeBook() 
{
    cout << "Enter the title of the book to remove: ";
    string title;
    cin.ignore();
    getline(cin, title);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

// ===================================== //
// Function to add a user to the library //
// ===================================== //
void Library::addUser() 
{
    string name;
    int type;

    cout << "Enter 1 for Student, 2 for Faculty: ";
    cin >> type;
    cin.ignore();  

    cout << "Enter Name: ";
    getline(cin, name);

    User* newUser = nullptr;
    if (type == 1) 
    {
        newUser = new Student(name);
    }
    else 
    {
        newUser = new Faculty(name);
    }

    users.push_back(newUser);

    // Print out the assigned user ID so the person knows what ID to use later
    cout << "User Added with ID: " << newUser->getUserID() << endl;
}

// ====================================== //
// Function to edit a user in the library //
// ====================================== //
void Library::editUser() 
{
    cout << "Enter the user ID to edit: ";
    int userID;
    cin >> userID;
    cin.ignore();

    for (auto user : users) 
    {
        if (user->getUserID() == userID) 
        {
            cout << "Enter new name: ";
            string newName;
            getline(cin, newName);
            user->setName(newName);
            cout << "User updated successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

// ======================================== //
// Function to remove a user in the library //
// ======================================== //
void Library::removeUser() 
{
    cout << "Enter the user ID to remove: ";
    int userID;
    cin >> userID;

    for (auto it = users.begin(); it != users.end(); ++it) 
    {
        if ((*it)->getUserID() == userID) 
        {
            delete* it;  // Free memory
            users.erase(it);
            cout << "User removed successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

// ========================================== //
// Function to checkout a book in the library //
// ========================================== //
void Library::bookCheckOut() 
{
    cout << "Enter the user ID: ";
    int userID;
    cin >> userID;
    cin.ignore(); // flush newline

    User* foundUser = nullptr;
    for (auto user : users) 
    {
        if (user->getUserID() == userID) 
        {
            foundUser = user;
            break;
        }
    }
    if (!foundUser) 
    {
        cout << "User not found." << endl;
        return;
    }

    cout << "Enter the title of the book to check out: ";
    string bookTitle;
    getline(cin, bookTitle);

    for (auto& book : books) 
    {
        if (book.getTitle() == bookTitle) 
        {
            if (!book.isAvailable()) 
            {
                cout << "Sorry, that book is currently unavailable." << endl;
                return;
            }
            book.setAvailable(false);
            foundUser->incrementBorrowedBookCount(); 

            cout << "Book checked out successfully!\n";
            return;
        }
    }

    cout << "Book not found in the library." << endl;
}

// ========================================== //
// Function to check in a book in the library //
// ========================================== //
void Library::bookCheckIn() 
{
    cout << "Enter the user ID: ";
    int userID;
    cin >> userID;
    cin.ignore(); 

    User* foundUser = nullptr;
    for (auto user : users) {
        if (user->getUserID() == userID) {
            foundUser = user;
            break;
        }
    }
    if (!foundUser) {
        cout << "User not found." << endl;
        return;
    }

    cout << "Enter the title of the book to check in: ";
    string bookTitle;
    getline(cin, bookTitle);

    for (auto& book : books) 
    {
        if (book.getTitle() == bookTitle) 
        {
            if (!book.isAvailable()) 
            {
                book.setAvailable(true);
                foundUser->decrementBorrowedBookCount(); 
                cout << "Book checked in successfully!\n";
                return;
            }
            else 
            {
                cout << "This book was already marked as available.\n";
                return;
            }
        }
    }
    cout << "Book not found in the library." << endl;
}

// ============================================= //
// Function to list all the books in the library //
// ============================================= //
void Library::listAllBooks() 
{
    cout << "\nList of All Books:" << endl;
    cout << "=================================" << endl;

    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    for (const auto& book : books) 
    {
        cout << "Title: " << book.getTitle()
            << "\nAuthor: " << book.getAuthor()
            << "\nISBN: " << book.getISBN()
            << "\nAvailable: " << (book.isAvailable() ? "Yes" : "No")
            << "\n--------------------------------\n";
    }
}

// ============================================= //
// Function to list all the users in the library //
// ============================================= //
void Library::listAllUsers() 
{
    cout << "\nList of All Users:" << endl;
    cout << "=================================" << endl;

    if (users.empty()) 
    {
        cout << "No users found.\n";
        return;
    }

    for (const auto& user : users) 
    {
        cout << "User ID: " << user->getUserID()
            << "\nName: " << user->getName()
            << "\nBorrowed Books: " << user->getBorrowedBookCount()
            << "\n--------------------------------\n";
    }
}