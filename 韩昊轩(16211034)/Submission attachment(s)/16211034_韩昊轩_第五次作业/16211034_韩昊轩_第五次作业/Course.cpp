#include "Course.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
Course::Course(const string s, int hour)
{
    name = s;
    creditHour = hour;
}
void Course::setCourse(const string s)
{
    name = s;
}
Course::~Course()
{
    //dtor
}
ostream& operator<<(ostream &Cout, Course & course)
{
    Cout<<"课程名："<<course.name<<"  学分"<<course.creditHour<<endl;
    return Cout;
}
