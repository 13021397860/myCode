#include "MyException.h"

MyException::MyException(ExceptionType et):eType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::err() const
{
    switch(eType)
    {
    case DATE_INVALID:
        return "日期不合法！";
    case RANGE_INVALID:
        return "成绩不合法！";
    case SCORE_INVALID:
        return "成绩不合法！";
    default:
        return "";
    }
}
