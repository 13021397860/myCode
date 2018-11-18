
#include <iostream>
#include "electivecourse.h"
#include "string"
using namespace std;



ElectiveCourse::ElectiveCourse(string n, int h) : Course(n, h)

{
	//ctor
	type = 0;
	grade = 0;
}

int ElectiveCourse::getScore() const
{
	if (grade == 'A')
	{
		return 95;
	}
	if (grade == 'B')
	{
		return 85;
	}
	if (grade == 'C')
	{
		return 75;
	}
	if (grade == 'D')
	{
		return 65;
	}
	if (grade == 'E')
	{
		return 55;
	}

}


ElectiveCourse ::~ElectiveCourse()
{
	//dtor
}

