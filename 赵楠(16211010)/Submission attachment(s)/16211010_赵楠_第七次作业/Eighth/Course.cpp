#include "Course.h"
#include <iostream>
using namespace std;
Course::Course()
{
	name="Tom";
	creditHour=0;
}

Course::Course(string nam,int credit)
{
	setName(nam);
	setCredit(credit);
}

void Course::setScore(int)
{
	
}

void Course::setName(string nam)
{
	name=nam;
}

void Course::setCredit(int ch)
{
	creditHour=ch;
}

int Course::getScore()const
{
	
}

string Course::getName()const
{
	return name;
}

int Course::getCredit()const
{
	return creditHour;
}

ostream &operator<<(ostream &output,const Course& C)
{
	output<<"课程名: "<<"<"<<C.getName()<<">"<<"学分: "<<"<"<<C.getCredit()<<">"<<"成绩: "<<"<"<<C.getScore()<<">";
}

Course::~Course()
{
}
