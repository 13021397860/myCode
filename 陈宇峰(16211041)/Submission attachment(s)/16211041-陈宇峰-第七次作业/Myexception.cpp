#include "Myexception.h"

MyException::MyException(ExceptionType et)
{
    myexceptiontype=et;
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const
{
    const char* myetname;
    switch (myexceptiontype)
    {
    case 0:
        myetname="DATE_INVALID";
        break;
    case 1:
        myetname="RANGE_ERROR";
        break;
    case 2:
        myetname="SCORE_INVALID";
        break;
    }
    return myetname;
    //return myexceptiontype;
}
