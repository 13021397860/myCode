#include "myexception.h"
#include <iostream>
using namespace std;
MyException::MyException(MyExceptionType e)
{
    ex=e;
    //ctor
}

MyException::~MyException()
{
    //dtor
}
 const char* MyException::what() const
{
    if(ex==DATE_INVALID)
    {
        return "DATE_INVALID";
    }
    else if(ex==RANGE_ERROR)
    {
        return "RANGE_ERROR";
    }
    else if(ex==SCORE_INVALID)
    {
        return "SCORE_INVALID";
    }
}
