#include "MyException.h"

MyException::MyException(Type e)
    :T(e)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const
{
    switch(T)
    {
    case date:
        return "The date is illegal!";
    case student:
        return "The subscript is out of range!";
    case gra:
        return "The score is illegal!";
    default:
        return "";
    }
}
