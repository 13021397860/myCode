#include "ArrException.h"
#include <iostream>
using namespace std;

ArrException::ArrException()
{
    message=new char[1000];
    //ctor
}
ArrException::~ArrException()
{
    //dtor
}
bool ArrException::ArrExceptionCheck(int a,int b)
{
    try
    {
        if(a<=0||a>b)
            throw a;
    }
    catch(int s)
    {
        cout<<"�쳣�������±�Խ�磬����������\n";
        return false;
    }
    return true;
}
