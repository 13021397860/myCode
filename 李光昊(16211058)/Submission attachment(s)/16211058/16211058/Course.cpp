#include "Course.h"
#include<iostream>
#include<iomanip>
using namespace std;

Course::Course(string aname,int acredit)
{
	setName(aname);
	setCreditHour(acredit);
	//cout<<"constructor course\n";
}

Course::Course()
{
	setName("unnamed course");
	setCreditHour(0);
	//cout<<"constructor course\n";
}

Course::~Course()
{
	//cout<<"destructor course\n";
}

Course& Course::setName(const string &aname)
{
	name=aname;
	return *this;
}

Course& Course::setCreditHour(int acredit)
{
	creditHour=acredit;
	return *this;
}
string Course::getName()const
{
	return name;
}
int Course::getCreditHour()const
{
	return creditHour;
}

//
ostream &operator<<(ostream &output,const Course &c)
{
	output<<"name: "<<setw(5)<<left<<c.getName()<<" credithour: "<<setw(3)<<left<<c.getCreditHour()<<" grade: ";
	int s=c.getScore();
	if(s==-1)output<<"none";
	else output<<s;
	return output;
}
/*
void Course::print()const
{
	cout<<"课程名："<<name<<"   学分："<<creditHour<<"\n";
}
*/
//
