#include "ElectiveCourse.h"
#include "MyException.h"

ElectiveCourse::ElectiveCourse(const string &s,const int &c):Course(s,c)
{
	setCourseName(s);
	setCreditHour(c);
	setGrade('E');
}
bool ElectiveCourse::setGrade(char g)
{
	if (g>='A'&&g<='E')
	{
		grade=g;
		return true;
	}
	else
	{
		grade='E';
		return false;
	}
}
int ElectiveCourse::getScore() const
{
	if (grade=='A') return 95;
		else if (grade=='B') return 85;
			else if (grade=='C') return 75;
				else if (grade=='D') return 65;
					else if (grade=='E') return 55;
}
ElectiveCourse::~ElectiveCourse()
{
}
