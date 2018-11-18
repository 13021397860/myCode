#include<iostream>
#include<cstring>
#include "Course.h"
using namespace std;
Course::Course()
{
	
}
Course::Course(string a,int b)
{
	cname=a;
	creditHour=b;
}
Course::~Course()
{
	
}
void Course::setCourse(const string c)
{
	cname=c;
}
string Course::getCourseName()
{
	return cname;
}
int const Course::getCredit() const
{
	return creditHour;
}
void Course::setCredit(int i)
{
	creditHour=i;
}
void Course::setCourseName(string i)
{
	cname=i;
}
ostream& operator << (ostream &output, Course &c)
{
	output<<"Course Name£º "<<c.cname<<";    Credit£º "<<c.creditHour;
	return output; 
}

