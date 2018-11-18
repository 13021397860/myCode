#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <iostream>
class MyException
{
protected:
    const char* message;
public:
    MyException(char* a):message(a){}
    const char* what() const {return message;}
};

#endif // MY_EXCEPTION_H
