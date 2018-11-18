#include "obligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(string courseName, int credit, int m)
:Course(courseName, credit), mark(m)
{
	
}

int ObligatoryCourse::getScore() const	{return mark;}

ObligatoryCourse &ObligatoryCourse::setMark(const int m)
{
	mark = m;
	return *this;
}

ObligatoryCourse::~ObligatoryCourse()
{
	
}
