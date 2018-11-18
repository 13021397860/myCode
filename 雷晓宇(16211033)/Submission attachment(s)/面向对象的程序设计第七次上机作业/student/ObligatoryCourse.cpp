#include "ObligatoryCourse.h"
#include "MyException.h"

ObligatoryCourse::ObligatoryCourse(const string &s,const int &c):Course(s,c)
{
	setCourseName(s);
	setCreditHour(c);
	setMark(0);
}
bool ObligatoryCourse::setMark(int m)
{
	if ((m<=100)&&(m>=0)) 
	{
		mark=m;
		return true;
	}
	else
	{
		mark=0;
		return false;
	}
}
int ObligatoryCourse::getScore() const
{
	return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
}
