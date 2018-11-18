#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "my_exception.h"
using std::string;

class Course
{
    friend std::ostream& operator<< (std::ostream& out, Course & A)
    {out << "Name:" << A.name << '\t' << "CreditHour:" << A.creditHour << '\t' << "Score: " << A.getScore();}
protected:
    string name;
    int creditHour;
public:
    Course(const string& _name = "NULL", int _credit = 0)    {setName(_name); setCredit(_credit);}
    string getName() const      {return name;}
    int getCredit() const       {return creditHour;}
    void setName(const string& _name)  {name = _name;}
    void setCredit(int _credit)            {creditHour = _credit;}
    virtual int getScore() = 0;
    void print(){std::cout << "CourseName: " << name << '\t' << "CreditHour: " << creditHour << std::endl;};
};

#endif // COURSE_H
