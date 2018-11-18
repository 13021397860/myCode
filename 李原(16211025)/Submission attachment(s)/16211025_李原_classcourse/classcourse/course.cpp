#include "course.h"
#include<iostream>
#include<string>
using namespace std;
Course::Course()
{
	name="xxx";
	creditHour=0;
}
Course::Course(string _name,int _creditHour)
{
	name=_name;creditHour=_creditHour;
}
Course::Course(const Course &C)
{
	name=C.name;
	creditHour=C.creditHour;
}
void Course::setName(string _name)
{
	name=_name;
}
void Course::setCredit(int _creditHour)
{
	creditHour=_creditHour;
}
/*void Course::setScore(int x)
{
	1==1;
}
int Course::getScore()
{
	return 1;
}*/

void ObligatoryCourse::setScore(int _mark)
{
	mark=_mark;
}
ObligatoryCourse::ObligatoryCourse()
{
	mark=0;
}

ObligatoryCourse::ObligatoryCourse(string _name,int _creditHour,int _mark):Course(_name , _creditHour)
{
	mark=_mark;
}
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse & O):Course(O.name, O.creditHour)
{
	mark=O.mark;
}
ElectiveCourse::ElectiveCourse()
{
	grade='E';
}
ElectiveCourse::ElectiveCourse(string _name,int _creditHour,char _grade):Course(_name, _creditHour)
{
	grade=_grade;
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse & E):Course(E.name,E.creditHour)
{
	grade=E.grade;
}
void ElectiveCourse::setScore(char _grade)
{
	grade=_grade;
}
int ElectiveCourse::getScore()const
{
	if(grade=='A')return 95;
	else if(grade=='B')return 85;
	else if(grade=='C')return 75;
	else if(grade=='D')return 65;
	else if(grade=='E')return 55;
	else return 0;
}
