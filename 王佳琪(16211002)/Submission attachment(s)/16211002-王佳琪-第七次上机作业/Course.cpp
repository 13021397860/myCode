#include<iostream>
#include "Course.h"
using namespace std;

ostream& operator<< (ostream& os,const Course & c)
{
	os<<"课程名 : "<<c.name<<"   "<<"学分 : "<<c.creditHour<<endl; 
	return os;
}

Course::Course(int hour ,string n)
{
	setCourse(hour ,n);
}

Course::~Course(){}

int Course::getCreditHour()
{
	return creditHour;
}

string Course::getName()
{
	return name;
}

void Course::setScore(const int score){}
        
void Course::setCreditHour(const int hour)
{
	creditHour = hour;
}
        
void Course::setName(const string n)
{
	name = n;
}
        
void Course::setCourse(const int hour, const string n)
{
	setCreditHour(hour);
	setName(n);
}

int Course::getScore() const {}

