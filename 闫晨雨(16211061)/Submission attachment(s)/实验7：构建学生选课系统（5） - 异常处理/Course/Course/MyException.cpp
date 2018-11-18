#include "MyException.h"

MyException::MyException(ExceptionType et)
{
    exceptionType = et;
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what()const
{
    if(exceptionType == DATE_INVALID)
        return "date invalid";
    else if(exceptionType == RANGE_ERROR)
        return "range error";
    else if(exceptionType == SCORE_INVALID)
        return "score invalid";

}
