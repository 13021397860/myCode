#include "MyException.h"

MyException::MyException()
{
    error="untitled error!";
    //ctor
}

MyException::MyException(string &a)
{
    error=a;
}

MyException::MyException(const char* a)
{
    error=a;
}

MyException::~MyException()
{
    //dtor
}

string MyException::Get_Exception()
{
    return error;
}

ostream & operator << (ostream &output,MyException &x)
{
    output<<x.Get_Exception();
    return output;
}
