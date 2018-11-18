#include "Exception.h"

Exception::Exception(ExceptionType et):exceptiontype(et)
{
    //ctor
}

Exception::~Exception()
{
    //dtor
}
char* Exception::what() const
{
    switch(exceptiontype)
    {
        case Date_Invalid:
            return "Date wrong!";
        case Grade_Invalid:
            return "Grade wrong!";
        case Range_Invalid:
            return "Range wrong!";
        default:
            return "Unknown wrong!";
    }
}
