#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
using namespace std;
enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID};
class MyException
{
    public:
        MyException();
        virtual ~MyException();
        virtual const char* what()const=0;
    protected:
    private:
        ExceptionType exceptionType;
};
class Date_exception : public MyException{
    public:
        virtual const char* what()const{
            return "Date Input Error!";
        }

};
class Course_exception : public MyException{
    public:
        virtual const char* what()const{
            return "Number Input Error!";
        }

};
class Mark_exception : public MyException{
    public:
        virtual const char* what()const{
            return "Mark Input Error!";
        }
};

#endif // MYEXCEPTION_HF:\2017project\student\MyException.h
