#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include "MyException.h"
using namespace std;


MyException::MyException()
{
    //ctor
}

MyException::MyException(ExceptionType et)
{

}

MyException::~MyException()
{
    //dtor
}

char* MyException::what()
{
    if(exceptionType==TIME_INVALID)
        return "Time invalid";
    if(exceptionType==RANGE_ERROR)
        return "range error";
    if(exceptionType==SCORE_INVALID)
        return "score invalid";
}
