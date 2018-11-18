#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>

class MyException
{
    public:
        MyException();
        virtual ~MyException();
        MyException(const MyException& other);
        MyException& operator=(const MyException& other);

    private:
    const char *message;
};

#endif
