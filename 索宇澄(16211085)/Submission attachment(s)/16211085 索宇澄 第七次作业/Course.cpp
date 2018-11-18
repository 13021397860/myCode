#include"Course.h"
#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;

ostream & operator<<(ostream & out, const Course & A)
{
    out <<"课程名："<< A.getCourseName() <<" 学分："<< A.getCreditHour()<<" 成绩："<< A.getScore();
    return out;
}

Course::Course()
{
	cout<<"ready"<<endl;
}

Course::Course(string a, int b) 
{
    setName(a);
    setcreditHour(b);
} 

Course::Course(const Course &a)
{
    setName(a.Name);
    setcreditHour(a.creditHour);
}


Course &Course::setName(string a)
{
    Name = a;	
    return *this;
}

Course &Course::setcreditHour(int a)
{
    creditHour=a;	
    return *this;
}

Course::~Course()
{
 
}


