#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User 
{
public:
    Student(string name);
    string getUserType() const override;
};

#endif // STUDENT_H