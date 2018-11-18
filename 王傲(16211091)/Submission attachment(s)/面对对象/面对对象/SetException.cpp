#include "SetException.h"
#include <iostream>
using namespace std;

SetException::SetException()
{
    message=new char[1000];
    //ctor
}
SetException::~SetException()
{
    //dtor
}

bool SetException::SetExceptionChecki(int u)
{
    try
    {
        if(u<0||u>100)
            throw u;
    }
    catch(int s)
    {
        cout<<"异常：输入必修课成绩错误，请重新输入\n";
        return false;
    }
    return true;
}

bool SetException::SetExceptionCheckc(char uu)
{
    try
    {
        if(uu<'A'||uu>'E')
            throw uu;
    }
    catch(char s)
    {
        cout<<"异常：输入选修课成绩错误，请重新输入\n";
        return false;
    }
    return true;
}

