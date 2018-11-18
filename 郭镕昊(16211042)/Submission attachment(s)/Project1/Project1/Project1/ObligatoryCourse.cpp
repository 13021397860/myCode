#include "ObligatoryCourse.h"
#include "MyException.h"
ObligatoryCourse::ObligatoryCourse(const string & n, int h)
	:Course(n, h)
{
	mark = 0;
}

ObligatoryCourse::ObligatoryCourse(const Course & a)
	:Course(a)
{
	mark = 0;
}

ObligatoryCourse::~ObligatoryCourse()
{
}
