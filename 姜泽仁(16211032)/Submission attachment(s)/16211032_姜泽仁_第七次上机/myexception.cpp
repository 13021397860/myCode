#include "myexception.h" // class's header file

// class constructor
MyException::MyException(ExceptionType type):exceptionType(type)
{
	// insert your code here
}

// class destructor
MyException::~MyException()
{
	// insert your code here
}
const char* MyException::what() const
{
    switch(exceptionType)
    {
    case DATE_INVALID:
        return "日期非法";
    case RANGE_ERROR:
        return "下标越界";
    case SCORE_INVALID:
        return "成绩非法";
    default:
        return "";
    }
}

