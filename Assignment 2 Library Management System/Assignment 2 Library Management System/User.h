#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class User 
{
protected:
    string name;
    int userID;
    vector<Book*> borrowedBooks;
    static int nextID;

public:
    User(string name);
    virtual string getUserType() const = 0;
    string getName() const;
    int getUserID() const;
    void borrowBook(Book* book);
    void returnBook(Book* book);
    void setName(const string& newName) { name = newName; }
    int getBorrowedBookCount() const { return borrowedBooks.size(); }

    void incrementBorrowedBookCount();
    void decrementBorrowedBookCount();
};

#endif // USER_H

