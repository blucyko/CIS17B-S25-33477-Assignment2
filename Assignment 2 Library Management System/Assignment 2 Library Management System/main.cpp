// Ash Nguyen
// CIS-17B-S25-33477
// 3/10/25
// Assignment 2 Library Management System

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

// Function Prototypes
void displayMenu();
void manageBooksMenu(Library& collegeLibrary);
void manageUsersMenu(Library& collegeLibrary);
void manageTransactionsMenu(Library& collegeLibrary);

int main()
{
    Library& collegeLibrary = Library::getInstance(); // Singleton instance

    // Constants for menu choices
    const int MANAGE_BOOKS_CHOICE = 1;
    const int MANAGE_USERS_CHOICE = 2;
    const int MANAGE_TRANSACTIONS_CHOICE = 3;
    const int QUIT_CHOICE = 4;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case MANAGE_BOOKS_CHOICE:
            manageBooksMenu(collegeLibrary);
            break;
        case MANAGE_USERS_CHOICE:
            manageUsersMenu(collegeLibrary); 
            break;
        case MANAGE_TRANSACTIONS_CHOICE:
            manageTransactionsMenu(collegeLibrary); 
            break;
        case QUIT_CHOICE:
            cout << "Thank you for using the Library Management System!" << endl;
            break;
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    } while (choice != QUIT_CHOICE);

    return 0;
}

//******************************************//
//                   Functions             //
//******************************************//

// ============================= //
// Function to display main menu //
// ============================= //
void displayMenu()
{
    cout << "\nWelcome to Library:" << endl;
    cout << "=================================" << endl;
    cout << "1. Manage Books" << endl;
    cout << "2. Manage Users" << endl;
    cout << "3. Manage Transactions" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// ======================================== //
// Function to display book management menu //
// ======================================== //
void manageBooksMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "\nManage Books:" << endl;
        cout << "=================================" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Edit a Book" << endl;
        cout << "3. Remove a Book" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            collegeLibrary.addBook();
            cout << endl;
            break;
        case 2:
            collegeLibrary.editBook();
            cout << endl;
            break;
        case 3:
            collegeLibrary.removeBook();
            cout << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 4);
}

// ======================================== //
// Function to display user management menu //
// ======================================== //
void manageUsersMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "\nManage Users:" << endl;
        cout << "=================================" << endl;
        cout << "1. Add a User" << endl;
        cout << "2. Edit a User" << endl;
        cout << "3. Remove a User" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            collegeLibrary.addUser();
            cout << endl;
            break;
        case 2:
            collegeLibrary.editUser();
            cout << endl;
            break;
        case 3:
            collegeLibrary.removeUser();
            cout << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 4);
}

// =============================================== //
// Function to display transaction management menu //
// =============================================== //
void manageTransactionsMenu(Library& collegeLibrary)
{
    int choice;
    do {
        cout << "\nManage Transactions:" << endl;
        cout << "=================================" << endl;
        cout << "1. Check Out A Book" << endl;
        cout << "2. Check In A Book" << endl;
        cout << "3. List All Books" << endl;
        cout << "4. List All Users" << endl;
        cout << "5. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            collegeLibrary.bookCheckOut();
            cout << endl;
            break;
        case 2:
            collegeLibrary.bookCheckIn();
            cout << endl;
            break;
        case 3:
            collegeLibrary.listAllBooks();
            cout << endl;
            break;
        case 4:
            collegeLibrary.listAllUsers();
            cout << endl;
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 5);
}

