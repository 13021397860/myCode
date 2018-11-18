#include "ObligatoryCourse.h"
#include "GradeException.h"

ObligatoryCourse::ObligatoryCourse(string courseName, int credit, int _mark)
:Course(courseName, credit), mark(_mark)
{
	
}

ObligatoryCourse &ObligatoryCourse::setMark(const int _mark)
{
	if(_mark > 100 || _mark < 0)
		throw GradeException();
	else mark = _mark;
	return *this;
}

ObligatoryCourse::~ObligatoryCourse()
{
	
}
