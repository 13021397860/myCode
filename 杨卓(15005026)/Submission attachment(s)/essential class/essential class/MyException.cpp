#include "MyException.h"

MyException::MyException(Exceptiontype et):ext(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char * MyException::what() const{
    switch(ext){
    case DATE_INVALID:
        return "The data's  format is invalid!";
    case RANGE_ERROR:
        return "The subscript is out of range!";
    case SCORE_INVALID:
        return "The score's format is invalid!";
    default:
        return "";

    }
}
