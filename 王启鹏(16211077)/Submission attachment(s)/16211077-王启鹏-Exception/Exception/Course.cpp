#include "Course.h"

Course::Course(const string n, const int c)
{
    setName(n);
    setCreditHour(c);
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setName(const string n)
{
    name=n;
    return ;
}

void Course::setCreditHour(const int c)
{
    creditHour=c;
    return ;
}

string Course::getName()const
{
    return name;
}

ostream& operator<<(ostream &output, const Course& c)
{
    output<<"课程名："<<c.name<<"   学分："<<c.creditHour<<"   成绩："<<c.getScore();
    return output;
}

double Course::getNumber() const//virtual
{
    return 1;
}
double Course::getCreditHour() const//virtual
{
    double ans=creditHour;
    return ans;
}
