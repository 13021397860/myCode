#include "Course.h"
#include<iostream>
#include<string>
using namespace std;

Course::Course(const string s,const int c)
{
	setCourseName(s);
	setCreditHour(c);
}
void Course::setCourseName(const string s)
{
	name=s;
}
void Course::setCreditHour(const int c)
{
	creditHour=c;
}
string Course::getName() const
{
	return name;
}
int Course::getCreditHour() const
{
	return creditHour;
}
ostream& operator<<(ostream& output,const Course& p){
	output<<"课程名："<<p.getName()<<" 学分："<<p.getCreditHour()<<" 成绩："<<p.getScore()<<endl;
    return output;
}
Course::~Course()
{
}
