#include<iostream>
#include<stdexcept>
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
using namespace std;


class MyException
{
    public:
        MyException(char *);
        void what() const;
        virtual ~MyException();

    protected:

    private:
        char *s;
};

#endif // MYEXCEPTION_H
