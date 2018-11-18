#include "MyException.h"
#include <iostream>

using namespace std;

MyException::MyException()
    :exceptionInfor("")
{

}

MyException::MyException(string s)
    :exceptionInfor(s)
{

}

MyException::MyException(const MyException &_e)
    :exceptionInfor(_e.exceptionInfor)
{

}

MyException::~MyException()
{
    //dtor
}

string MyException::what()
{
    return exceptionInfor;
}
