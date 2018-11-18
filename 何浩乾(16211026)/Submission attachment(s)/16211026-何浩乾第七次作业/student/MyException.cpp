#include "MyException.h"

MyException::MyException(ExceptionType et):exceptionType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what()
{
    switch(exceptionType)
    {
    case DATE_INVALID:
        return "The date's format is invalid!";
    case RANGE_ERROR:
        return "out of range!";
    case SCORE_INVALID:
        return "The score's format is invalid!";
    default:
        return "";
    }
}
