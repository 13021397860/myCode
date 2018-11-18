#include "oblitarycourse.h"

OblitaryCourse::OblitaryCourse()
{
}
OblitaryCourse::OblitaryCourse(const string tname,const int tcreditHour)
{
	name=tname;
	creditHour=tcreditHour;
	mark=0;
}
OblitaryCourse::OblitaryCourse(const string tname,const int tcreditHour,const int tmark)
{
	name=tname;
	creditHour=tcreditHour;
	mark=tmark;
}
OblitaryCourse::OblitaryCourse(const OblitaryCourse &O):Course(O)
{
	mark=O.mark;
}
int OblitaryCourse::getMark()const
{
	return mark;
}
int OblitaryCourse::setMark(int tmark)
{
	if(0<=tmark&&tmark<=100) 
	mark=tmark;
	else 
	{MyException a=SCORE_INVALID;throw a;return 0;} 
}
int OblitaryCourse::getScore()const
{
	return mark;
}
void OblitaryCourse::printCourse()const
{
		cout<<"必修科目:"<<name;
		printf(",学分:%d,得分:%d\n",creditHour,getScore());
}
