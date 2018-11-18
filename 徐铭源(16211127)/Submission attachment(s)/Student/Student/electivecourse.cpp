#include "electivecourse.h"
#include<cstdio>
ElectiveCourse::ElectiveCourse()
{
	
}
ElectiveCourse::ElectiveCourse(const string tname,const int tcreditHour)
{
	name=tname;
	creditHour=tcreditHour;
}
ElectiveCourse::ElectiveCourse(const string tname,const int tcreditHour,const char tgrade)
{
	name=tname;
	creditHour=tcreditHour;
	grade=tgrade;
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse &E):Course(E)
{
	grade=E.grade;
}
int ElectiveCourse::getGrade()const
{
	return grade;
}
int ElectiveCourse::setGrade(char tgrade)
{
	if(tgrade>='A'&&tgrade<='E')
	{grade=tgrade;return 1;}
	else 
	{MyException a=SCORE_INVALID; throw a; return 0;} 
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
	return 0;
}
void ElectiveCourse::printCourse()const
{
	cout<<"选修科目:"<<name;
	printf(",学分:%d,得分:%d\n",creditHour,getScore());
}
ElectiveCourse::~ElectiveCourse()
{
}
