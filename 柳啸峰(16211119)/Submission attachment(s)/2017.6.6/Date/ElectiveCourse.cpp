#include "ElectiveCourse.h"
#include "Course.h"
#include <iomanip>
#include <iostream>
ElectiveCourse::ElectiveCourse(char a ,string b ,int c ):Course(b, c )
{
	setGrade(a);
}
void ElectiveCourse::setGrade(char a)
{
	grade=(a=='A'||a=='B'||a=='C'||a=='D'||a=='E')?a:'0';
}
int ElectiveCourse::getScore()const
{
	switch(grade)
	{
		case 'A':return 95;
		case 'B':return 85;
		case 'C':return 75;
		case 'D':return 65;
		case 'E':return 55;
	}
}
void ElectiveCourse::printCourse()
{
	cout<<setw(10)<<left<<getName()<<getCreditHour()<<"  "<<getScore()<<endl;
}
ElectiveCourse::~ElectiveCourse()
{
}
