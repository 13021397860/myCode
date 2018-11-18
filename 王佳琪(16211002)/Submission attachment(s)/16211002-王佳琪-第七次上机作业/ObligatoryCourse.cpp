#include "ObligatoryCourse.h"

/*
ObligatoryCourse::ObligatoryCourse(int m)
{
	setScore(m);
}

ObligatoryCourse::~ObligatoryCourse(){}
*/

int ObligatoryCourse::getScore() const
{
	return mark;
}

void ObligatoryCourse::setScore(const int m)
{
	mark = m;
}

