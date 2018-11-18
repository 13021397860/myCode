#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
	:grade('E')
{
}

ElectiveCourse::ElectiveCourse(string s,int x)
	: grade('E')
{
	this->setName(s);
	this->setCreditHour(x);
}

ElectiveCourse::~ElectiveCourse()
{
}

int ElectiveCourse::getScore() const
{
	switch (grade)
	{
	case 'A':
		return 95;
		break;
	case 'B':
		return 85;
		break;
	case 'C':
		return 75;
		break;
	case 'D':
		return 65;
		break;
	case'E':
		return 55;
		break;
	default:
		return 55;
		break;
	}
}

void ElectiveCourse::setGrade(char c)
{
	if (c >= 65 && c <= 69)
		grade = c;
	else
	{
		throw MyException(Score_Invalid);
		grade = 'E';
	}
}
