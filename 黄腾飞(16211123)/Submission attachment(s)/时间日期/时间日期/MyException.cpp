#include "MyException.h"

MyException::MyException(ExceptionType et):wrong(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const
{
    switch(wrong)
    {
    case Date_wrong:
        return "The date's format is invalid!";
    case Number_wrong:
        return "The subscript is out of range!";
    case Grade_wrong:
        return "The score's format is invalid!";
    default:
        return "";
    }
}
