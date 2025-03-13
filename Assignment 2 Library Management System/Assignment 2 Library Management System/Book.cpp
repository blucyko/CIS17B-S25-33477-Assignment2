#include "Book.h"

Book::Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool status) { available = status; }