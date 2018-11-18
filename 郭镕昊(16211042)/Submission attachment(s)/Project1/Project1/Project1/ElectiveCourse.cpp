#include "ElectiveCourse.h"
#include "MyException.h"
ElectiveCourse::ElectiveCourse(const string & n, int h)
	:Course(n, h)
{
}

ElectiveCourse::ElectiveCourse(const Course & a)
	: Course(a)
{
}

ElectiveCourse::~ElectiveCourse()
{
}
