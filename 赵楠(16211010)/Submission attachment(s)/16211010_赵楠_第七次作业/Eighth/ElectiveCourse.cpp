#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string nam,const int credit,const char gra):Course(nam,credit)
{
	setGrade(gra);
}

void ElectiveCourse::setGrade(char g)
{
	if(g=='a'||g=='b'||g=='c'||g=='d'||g=='e')
	g=g-32;
	grade=g;
}

void ElectiveCourse::setScore(int m)
{
	char g;
	if(m>=90)
	g='A';
	else if(m>=80)
	g='B';
	else if(m>=70)
	g='C';
	else if(m>=60)
	g='D';
	else
	g='E';
	setGrade(g);
}
/*virtual */int ElectiveCourse::getScore()const
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
		case 'E':
			return 55;
			break;
	}
}

ElectiveCourse::~ElectiveCourse()
{
}
