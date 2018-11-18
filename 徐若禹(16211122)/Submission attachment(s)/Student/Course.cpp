#include "Course.h"

Course::Course(string n,int c)
{
    setName(n);
    setCreditHour(c);
}

void Course::setName(string n)
{
    name = n;
}

string Course::getName() const
{
    return name;
}

void Course::setCreditHour(int c)
{
    creditHour = (c > 0)? c:0;
}

int Course::getCreditHour() const
{
    return creditHour;
}

void Course::setCourse(string n, int c,int m)
{
    setName(n);
    setCreditHour(c);
    setMark(m);
}

void Course::setCourse(string n, int c,char g)
{
    setName(n);
    setCreditHour(c);
    setGrade(g);
}

ostream &operator<<(ostream &output,const Course &course)
{
    output << ".course:"  << course.name << "      credit hour:" << course.creditHour;
    return output;
}

Course::~Course()
{
    //dtor
}
