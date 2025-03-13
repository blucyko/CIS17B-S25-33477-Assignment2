#include "Student.h"

Student::Student(string name) : User(name) {}
string Student::getUserType() const { return "Student"; }