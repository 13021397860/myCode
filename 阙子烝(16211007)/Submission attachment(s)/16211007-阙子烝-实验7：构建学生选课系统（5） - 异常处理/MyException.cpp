#include "MyException.h"

MyException::MyException()
{
}

MyException::~MyException()
{
}

void MyException::DateException(Date d)
throw(Date)
{
	if(!d.check())
		throw d;
}

void MyException::CourseException(int num,int limit)
{
	if(num<=0||num>limit)
		throw num;
}

void MyException::GradeException(int score)
{
	if(score<0||score>100)
		throw score;
}
