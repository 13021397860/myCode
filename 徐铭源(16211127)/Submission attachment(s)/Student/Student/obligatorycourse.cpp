#include "obligatorycourse.h"
#include "Course.h"
#include<iostream>
using namespace std;
ObligatoryCourse::ObligatoryCourse()
{
	
}
ObligatoryCourse::ObligatoryCourse(const string tname,const int tcreditHour)
{
	name=tname;
	creditHour=tcreditHour;
}
void ObligatoryCourse::setMark(const int _mark)
{
	mark=_mark;
}
int ObligatoryCourse::getMark()
{
	return mark;
}
