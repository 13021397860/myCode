#include "Course.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& cout,const Course &c)
{
    cout<<"CourseName: "<<c.name<<"    CreditHour: "<<c.creditHour<<"    Grade: "<<c.getScore()<<endl;
    return cout;
}

Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setmark(const int n){}
int Course::getScore()const{return 0;}


void Course::setname(string n)
{
    name=n;
}

void Course::setcreditHour(int x)
{
    creditHour=x;
}

string Course::getname()
{
    return name;
}

int Course::getcreditHour()
{
    return creditHour;
}
