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
        cout<<"���ڲ��Ϸ������������룺";
    else if(type=="range")
        cout<<"�±겻�Ϸ������������룺"<<endl;
    else if(type=="grade")
        cout<<"�������Ϸ������������룺";
    return *this;
}
