#include "MyException.h"


MyException::MyException(int num)
{
    errornum = num;
    //ctor
}

void MyException::print() const
{
    cout << errormessage[errornum]<<endl;
}
MyException::~MyException()
{
    //dtor
}
