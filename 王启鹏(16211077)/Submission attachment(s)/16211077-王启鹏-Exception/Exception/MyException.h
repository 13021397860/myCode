#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<string>
#include<iostream>
using namespace std;

class MyException
{
    public:
        MyException(string);
        virtual ~MyException();
        MyException& whichType(string);
    protected:

    private:
};

#endif // MYEXCEPTION_H
