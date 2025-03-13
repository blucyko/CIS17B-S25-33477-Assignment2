#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book 
{
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(string title, string author, string isbn);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isAvailable() const;
    void setAvailable(bool status);
    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setISBN(const string& newISBN) { isbn = newISBN; }

};

#endif // BOOK_H

