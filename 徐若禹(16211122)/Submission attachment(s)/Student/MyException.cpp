#include "MyException.h"

MyException::MyException(char *c)
{
    s = c;
}

void MyException::what() const
{
    cout << s;
}

MyException::~MyException()
{
    //dtor
}
