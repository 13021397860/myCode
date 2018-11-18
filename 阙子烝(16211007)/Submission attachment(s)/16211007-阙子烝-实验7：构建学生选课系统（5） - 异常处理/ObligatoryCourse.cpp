#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
	mark=0;
}

void ObligatoryCourse::setScore(const int s)
{
	mark=s;
}

int ObligatoryCourse::getScore() const
{
	return mark;
}

