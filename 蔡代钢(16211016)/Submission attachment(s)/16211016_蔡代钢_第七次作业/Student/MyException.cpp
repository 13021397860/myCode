#include "MyException.h"
MyException::MyException()
{
    message1=new char [20];
    message2=new char [30];
    message3=new char [35];
    message1="Date entry error!";
    message2="Subscript out exception!";
    message3="Abnormal setting of scores!";
    //ctor
}
MyException::~MyException()
{
    delete[] message1;
    delete[] message2;
    delete[] message3;
    //dtor
}
