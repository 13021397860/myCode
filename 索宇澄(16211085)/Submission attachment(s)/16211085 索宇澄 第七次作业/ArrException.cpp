#include "ArrException.h"
#include <iostream>
using namespace std;

ArrException::ArrException()
{
    message=new char[1000];
}
ArrException::~ArrException()
{
   
}
bool ArrException::ArrExceptionCheck(int a,int b)
{
    try
    {
        if(a<0||a>=b)
            throw a;
    }
    catch(int s)
    {
        cout<<"����Ŀ�귶Χ������������"<<endl;
        return false;
    }
    return true;
}
