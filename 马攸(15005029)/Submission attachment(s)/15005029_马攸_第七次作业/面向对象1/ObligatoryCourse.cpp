#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string &s,const int &x):Course(s,x)
{
	setname(s);
	setCreditHour(x);
	setMark(100);
}
bool ObligatoryCourse::setMark(int x)
{
	if(x>=0&&x<=100)
	{
		Mark=x;
		return true;
	}
	else
	{
		Mark=0;
		return false;
	}
}
int ObligatoryCourse::getScore() const
{
	return Mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
}
