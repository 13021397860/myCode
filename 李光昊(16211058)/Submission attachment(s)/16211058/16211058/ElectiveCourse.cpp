#include "ElectiveCourse.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
using namespace std;

ElectiveCourse::ElectiveCourse()
{
	grade='a';
	//cout<<"constructor ElectiveCourse\n";
}

ElectiveCourse::ElectiveCourse(string s,int c)
:Course(s,c)
{
	grade='a';
	//cout<<"constructor ElectiveCourse\n";
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &e)
:Course(e.getName(),e.getCreditHour())
{
	grade='a';
	//cout<<"constructor ElectiveCourse\n";
}

ElectiveCourse::~ElectiveCourse()
{
	//cout<<"destructor ElectiveCourse\n";
}

ElectiveCourse& ElectiveCourse::setGrade(char agrade)
{
	if(agrade<'A'||agrade>'E')throw MyException("³É¼¨·Ç·¨£¡");
	grade=agrade;
}

char ElectiveCourse::getGrade()const
{
	return grade;
}

int ElectiveCourse::getScore()const
{
	if(grade=='A')return 95;
	else if(grade=='B')return 85;
	else if(grade=='C')return 75;
	else if(grade=='D')return 65;
	else if(grade=='E')return 55;
	else return -1;
}
