#include "Exception.h"

Exception::Exception(ExceptionType et):exceptionType(et)
{
    //ctor
}

Exception::~Exception()
{
    //dtor
}

char* Exception::what() const
{
    switch(exceptionType)
    {
    case DATE_INVALID:
        return "输入日期数据不符合！";
    case RANGE_ERROR:
        return "输入范围数据不符合！";
    case SCORE_INVALID:
        return "输入成绩数据不符合！";
    default:
        return "";
    }
}
