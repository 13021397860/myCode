#include "MyException.h"

MyException::MyException()
{
    //ctor
}
MyException::MyException(ExceptionType et):exceptionType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what()const
{
    switch(exceptionType)
    {
        case DATE_INVALID:
            return "日期错误!请重新输入~";
        case RANGE_ERROR:
            return "不在范围内!请重新输入~~";
        case SCORE_INVALID:
            return "成绩输入错误!请重新输入~";
        default:
            return "其他错误,请脑补解决~~";
    }
}
