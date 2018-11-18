#include "ElectiveCourse.h"
#include <string.h>

using namespace std;

ElectiveCourse::ElectiveCourse(string a,int b,char  c)
 	:Course(a,b),grade(c)
{
	
}

const double ElectiveCourse::getWeight()const
{
	return 0.4;
}
const int ElectiveCourse::getScore()const
{
	if(grade=='A')
	{
		return 95;
	}
	else if(grade=='B')
	{
		return 85;
	}
	else if(grade=='C')
	{
		return 75;
	}
	else if(grade=='D')
	{
		return 65;
	}
	else if(grade=='E')
	{
		return 55;
	}
}

ostream& operator<<(ostream& output,const ElectiveCourse &s)
{
	output<<"科目："<<s.getCoursename()<<" 学分:"<<s.getCoursecreditHour()<<" 成绩："<<s.getScore()<<"\n";
}
ElectiveCourse::~ElectiveCourse()
{
}
