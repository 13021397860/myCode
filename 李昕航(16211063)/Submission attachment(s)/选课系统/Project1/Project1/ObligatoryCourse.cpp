#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
	:mark(0)
{
}

ObligatoryCourse::ObligatoryCourse(string s,int x)
	:mark(0)
{
	this->setName(s);
	this->setCreditHour(x);
}

ObligatoryCourse::~ObligatoryCourse()
{
}

int ObligatoryCourse::getScore() const
{
	return mark;
}

void ObligatoryCourse::setGrade(int x)
{
	if (x >= 0 && x <= 100)
		mark = x;
	else
	{
		throw MyException(Score_Invalid);
		mark = 0;
	}
}
