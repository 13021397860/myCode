#include "ElectiveCourse.h"
#include<iostream>
#include <cstring>
#include <typeinfo>
ElectiveCourse::ElectiveCourse(string courseName, int credithour, char a)
:Course(courseName, credithour)
{
	grade=a;
}

ElectiveCourse &ElectiveCourse::setgrade(const char a)
{
	grade = a;
	return *this;
}

int ElectiveCourse::getScore() const
{
	switch(grade)
	{
		case 'A': return 95;
		case 'B': return 85;
		case 'C': return 75;
		case 'D': return 65;
		case 'E': return 55;
		default: return 0;
	}
}

ElectiveCourse::~ElectiveCourse()
{
	
}
