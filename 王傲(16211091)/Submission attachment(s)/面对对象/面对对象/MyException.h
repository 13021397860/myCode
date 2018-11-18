#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <stdexcept>

class MyException
{
    public:
        MyException();
        virtual ~MyException();

    protected:
    private:
    const char *message;
};

#endif // MYEXCEPTION_H
