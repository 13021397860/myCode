#include "MyException.h"
#include <iostream>
using namespace std;
MyException::MyException(ExceptionType et)
{
    exceptionType=et;
    //ctor
}
MyException::~MyException()
{
    //dtor
}
const char* MyException::errinfo() const
{
    if(exceptionType == DATE_INVALID)
    {
        return "DATE_INVALID";
    }
    else if(exceptionType == RANGE_ERROR)
    {
        return "RANGE_ERROR";
    }
    else if(exceptionType == SCORE_INVALID)
    {
        return "SCORE_INVALID";
    }
}
