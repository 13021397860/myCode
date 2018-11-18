#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string nam,const int credit,const int ma):Course(nam,credit)
{
	setMark(ma);
}

void ObligatoryCourse::setMark(int m)
{
	mark=m;
}

void ObligatoryCourse::setScore(int m)
{
	setMark(m);
}

/*virtual */int ObligatoryCourse::getScore()const
{
	return mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
}
