#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
using namespace std;

class MyException
{
    public:
        MyException(string ="invalid_Eorro");
        virtual ~MyException();
        void what();
    protected:

    private:
        string message;
};

#endif // MYEXCEPTION_H
