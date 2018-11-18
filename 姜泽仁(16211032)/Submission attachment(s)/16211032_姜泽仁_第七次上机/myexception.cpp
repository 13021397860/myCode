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
        return "���ڷǷ�";
    case RANGE_ERROR:
        return "�±�Խ��";
    case SCORE_INVALID:
        return "�ɼ��Ƿ�";
    default:
        return "";
    }
}

