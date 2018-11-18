#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType{TIME_INVALID,RANGE_ERROR,SCORE_INVALID};
class MyException
{
    public:
        MyException();
        MyException(ExceptionType et);
        virtual ~MyException();
        virtual char* what();

    protected:

    private:
        ExceptionType exceptionType;
};

#endif // MYEXCEPTION_H
