#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <stdexcept>

class MyException
{
    public:
        MyException();
        virtual ~MyException();
        MyException(const MyException& other);
        MyException& operator=(const MyException& other);

    protected:
    private:
    const char *message;
};

#endif 
