#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <cstring>
using namespace std;

class MyException
{
    public:
        MyException();
        MyException(string& a);
        MyException(const char* a);
        virtual ~MyException();
        string Get_Exception();
        friend ostream & operator << (ostream &, MyException &);
    protected:

    private:
        string error;
};

#endif // MYEXCEPTION_H
