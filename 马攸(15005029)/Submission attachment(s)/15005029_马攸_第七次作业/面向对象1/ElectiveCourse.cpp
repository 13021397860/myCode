#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string &s,const int &x):Course(s,x)
{
	setname(s);
	setCreditHour(x);
	setGrade('A');
}
bool ElectiveCourse::setGrade(char x)
{
	if(x=='A'||x=='B'||x=='C'||x=='D'||x=='E')
	{
		Grade=x;
		return true;
	}
	else
	{
		Grade='E';
		return false;
	}
	
}
int ElectiveCourse::getScore() const
{
	int Score=0;
	if(Grade=='A')
	{
		Score=95;
	}
	else if(Grade=='B')
	{
		Score=85;
	}
	else if(Grade=='C')
	{
		Score=75;
	}
	else if(Grade=='D')
	{
		Score=65;
	}
	else if(Grade=='E')
	{
		Score=55;
	}
	return Score;
}
ElectiveCourse::~ElectiveCourse()
{
}
