#ifndef OBLIGATORY_COURSE_H
#define OBLIGATORY_COURSE_H
#include "course.h"
#include <iostream>
class ObligatoryCourse: public Course
{
private:
    int mark;
public:
    ObligatoryCourse(const string& _name = "NULL", int _credit = 0, int _mark = 0): Course(_name, _credit)     {setScore(_mark);}
    void setScore(int _mark)            {if (_mark >= 0 && _mark <= 100) mark = _mark; else throw MyException("Grade Error.");}
    virtual int getScore()  {return mark;}
    //virtual void print() {std::cout << "Name:" << name << "\t\t" << "CreditHour:" << creditHour << "\t\t" << "Mark:" << mark << std::endl;}
};

#endif // OBLIGATORY_COURSE_H
