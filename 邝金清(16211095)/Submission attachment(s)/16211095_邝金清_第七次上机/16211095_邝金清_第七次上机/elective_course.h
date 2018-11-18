#ifndef ELECTIVE_COURSE_H
#define ELECTIVE_COURSE_H
#include "course.h"
#include <iostream>
class ElectiveCourse: public Course
{
private:
    char grade;
public:
    ElectiveCourse(const string& _name = "NULL", int _credit = 0, char _grade = 'E'): Course(_name, _credit)      {setScore(_grade);}
    void setScore(char _grade)  {if (_grade <= 'E' && _grade >= 'A')   grade = _grade; else throw MyException("Grade Error.");}
    virtual int getScore();
    //virtual void print() {std::cout << "Name:" << name << "\t\t" << "CreditHour:" << creditHour << "\t\t" << "Grade:" << grade << std::endl;}
};

#endif // ELECTIVE_COURSE_H
