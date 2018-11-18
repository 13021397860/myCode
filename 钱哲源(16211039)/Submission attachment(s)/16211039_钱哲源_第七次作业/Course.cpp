#include "Course.h"
#include<iostream>
using namespace std;


ostream& operator<<(ostream& output, const Course* co)
{
    output<<"course name:"<<co->name<<" credithour:"<<co->creditHour<<" score:"<<co->getScore()<<endl;
    return output;
}

Course::Course()
{

}

Course::Course(const string n,int h)
{
    setName(n);
    setHour(h);
}

string Course::getName() const
{
    return name;
}

int Course::getHour() const
{
    return creditHour;
}

void Course::setName(const string n)
{
    name=n;
}

void Course::setHour(int h)
{
    creditHour=h;
}

void Course::printx() const
{
    cout<<name<<"\n";
}
Course::~Course()
{
    //dtor
}
