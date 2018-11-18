#include "MyException.h"

MyException::MyException(ExceptionType type)
	:type(type)
{
}

MyException::~MyException()
{
}

const char*MyException::Identify()
{
	switch (type)
	{
	case Date_Invalid:
		return "Date is Invalid!";
	case Range_Error:
		return "Subscript is out of Range!";
	case Score_Invalid:
		return "Score is Invalid!";
	default:
		break;
	}
}
