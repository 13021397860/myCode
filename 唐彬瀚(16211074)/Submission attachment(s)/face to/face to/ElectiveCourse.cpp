#include<iostream>
#include<cstring>
#include "Course.h"
#include "ElectiveCourse.h"
ElectiveCourse::ElectiveCourse()
{
	
}
ElectiveCourse::ElectiveCourse(string c)
{
	ename=c;
}
ElectiveCourse::~ElectiveCourse()
{
	
}
void ElectiveCourse::setGrade(const char n)
{
	grade=n;
}
int const ElectiveCourse::getGrade() const
{
	switch(grade){
		case 'A':return 95;
		case 'B':return 85;
		case 'C':return 75;
		case 'D':return 65;
		case 'E':return 55;
	}
}
int ElectiveCourse::getScore()
{
	switch(grade){
		case 'A':return 95;
		case 'B':return 85;
		case 'C':return 75;
		case 'D':return 65;
		case 'E':return 55;
	}
}
string ElectiveCourse::getName()
{
	return ename;
}
ostream& operator << (ostream &output, ElectiveCourse &c)
{
	output<<"Course Name£º "<<c.ename<<";    Credit£º "<<c.getCredit();
	return output; 
}
