#include "MyException.h"

MyException::MyException(string type)
{
    //ctor
    whichType(type);
}

MyException::~MyException()
{
    //dtor
}

MyException& MyException::whichType(string type)
{
    if(type=="date")
        cout<<"日期不合法，请重新输入：";
    else if(type=="range")
        cout<<"下标不合法，请重新输入："<<endl;
    else if(type=="grade")
        cout<<"分数不合法，请重新输入：";
    return *this;
}
