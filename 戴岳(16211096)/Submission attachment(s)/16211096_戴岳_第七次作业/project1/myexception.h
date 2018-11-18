#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
using namespace std;

class MyException
{
    public:
        MyException();
        MyException(int);
        void what()const;
        virtual ~MyException();

    protected:

    private:
        int error;
        string a,b,c;
};

#endif // MYEXCEPTION_H
