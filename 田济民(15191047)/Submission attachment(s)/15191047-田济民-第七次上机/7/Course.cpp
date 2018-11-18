#include "Course.h"
#include<iostream>
#include<string>
using namespace std;
Course::Course()
{
    name="xiaoming";
    //ctor
}

Course::~Course()
{
    //dtor
}
Course::Course(string n,int s)
{
    name=n;
    creditHour=s;
}
int Course::getCreditHour()
{
    return this->creditHour;
}
bool Course::showName()
{
    cout<<this->name<<endl;
    return true;
}
void Course::setCreditHour(int x)
{
    creditHour=x;
}
bool Course::setName(string a)
{
    name=a;
    return true;
}
string Course::getName()
{
    return name;
}

