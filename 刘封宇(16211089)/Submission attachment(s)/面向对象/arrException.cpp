#include "arrException.h"
#include <iostream>
using namespace std;

ArrException::ArrException()
{
    message=new char[1000];

}

ArrException::ArrException(char *str)
{
    message=str;
}

bool ArrException::ArrExceptionCheck(int a,int b,bool c)
{
    try
    {
        if(a<=0||a>b||!c)
        throw a;
    }
    catch(int a)
    {
        cout<<"数据不合法！"<<endl;
        return false;
    }
    return true;
}

ArrException::~ArrException()
{
   
}

ArrException::ArrException(const ArrException& other)
{
  
}


