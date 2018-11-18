#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#include "MyException.h"

MyException::MyException(ExceptionType et):exceptionType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const
{
    switch(exceptionType)
    {
    case DATE_ILLEGAL:
        return "输入的日期不合法";
    case RANGE_ERROR:
        return "输入的下标不合法";
    case SCORE_ILLEGAL:
        return "输入的成绩不合法";
    default:
        return "";
    }
}
