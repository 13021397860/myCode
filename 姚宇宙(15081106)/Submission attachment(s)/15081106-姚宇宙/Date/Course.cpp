#include "Course.h"
#include <iostream>
#include <iomanip>
#define SIZE 32
using namespace std;

Course::Course()
{
    name = "Unknown";
    creditHour = 0;
    //cout << "default constructor of Course has been used.\n";
}

Course::Course(const string &n, int c)
{
    setName(n);
    setCreditHour(c);
    //cout << "parameter constructor of Course has been used.\n";
}

Course::Course(const Course &_copy)
    :name(_copy.name),
     creditHour(_copy.creditHour)
{
    //cout << "copy constructor of Course has been used.\n";
}

Course::~Course()
{
    //dtor
}

string Course::getName() const
{
    return name;
}

int Course::getCreditHour() const
{
    return creditHour;
}

void Course::setName(const string &n)
{
    if(n.length() > SIZE) name.assign(n, 0, SIZE);
    else if(n.length() == 0) return;
    else name = n;
}

void Course::setCreditHour(int c)
{
    if(c >= 0 and c <= 100)
    {
        creditHour = c;
    }
    else creditHour = 0;
}

ostream& operator << (ostream &os, const Course &_c)
{
    return os << "Course Name: " << left << setw(SIZE) << _c.getName() << " Credit Hour: " << _c.getCreditHour() << " Score: " << _c.getScore();
}
