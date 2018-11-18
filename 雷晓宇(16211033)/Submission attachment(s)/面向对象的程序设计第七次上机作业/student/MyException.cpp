#include "MyException.h"

MyException::MyException(ExceptionType et)
{
	exceptionType=et;
}
const char* MyException::what() const
{
	if (exceptionType==DATE_INVALID)
	{
		return "DATE_INVALID";
	}
	else if (exceptionType==RANGE_ERROR)
	{
		return "RANGE_ERROR";
	}
	else if (exceptionType==SCORE_INVALID)
	{
		return "SCORE_INVALID";
	}
}
MyException::~MyException()
{
}
