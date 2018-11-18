#include "MyException.h"



MyException::MyException(Exceptiontype a) :exception(a)
{
}


MyException::~MyException()
{
}

const char* MyException::what() const {
	switch (exception)
	{
	case Date_invalid:
		return "The date's format is invalid.";
	case Score_invalid:
		return "The score's format is invalid.";
	case Range_error://subscript ÏÂ±ês
		return "The subscript is out of range.";
	default:
		return "";
	}
}