#include "Course.h"

Course::Course()
{
    //ctor
}

Course::Course(const string s, const int h)
{
    name = s;
    creditHour = h;
}

Course::~Course()
{
    //dtor
}

ostream& operator <<(ostream &out, const Course& c)
{
    out << "course name:" << c.name << " credit hour:" << c.creditHour << " score:" << c.getScore();
    return out;
}

int Course::setCourse(const string s, const int h)
{
    name = s;
    creditHour = h;
    return 1;
}

int Course::getCourse(string &s, int &h)const
{
    s = name;
    h = creditHour;
    return 1;
}

