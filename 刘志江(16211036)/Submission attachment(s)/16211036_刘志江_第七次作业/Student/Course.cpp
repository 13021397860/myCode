#include "Course.h"

ostream& operator<<(ostream& output, Course& c)
{
    output << "Course name: " << c.name << " Credit hour: " << c.creditHour;
    if (c.setSc) output << " Score: " << c.getScore();
    return output;
}

Course::Course(const string n, const int ch)
{
    setSc=0;
    name=n;
    creditHour=ch;
}

string Course::getName() const
{
    return name;
}

void Course::setName(const string n)
{
    name=n;
}

void Course::setSetSc()
{
    setSc=1;
}

int Course::getSetSc()
{
    return setSc;
}

int Course::getCreditHour() const
{
    return creditHour;
}

void Course::setCreditHour(const int ch)
{
    creditHour=ch;
}

Course::~Course()
{
    //dtor
}
