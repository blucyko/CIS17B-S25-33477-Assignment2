#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

class Library 
{
private:
    vector<Book> books;
    vector<User*> users;
    Library() {}
    static Library* instance;

public:
    static Library& getInstance();
    ~Library();

    void addBook();
    void editBook();
    void removeBook();
    void listAllBooks();

    void addUser();
    void editUser();
    void removeUser();
    void listAllUsers();

    void bookCheckOut();
    void bookCheckIn();
};

#endif // LIBRARY_H