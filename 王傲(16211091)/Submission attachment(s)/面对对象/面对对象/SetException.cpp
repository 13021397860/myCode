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
        cout<<"�쳣��������޿γɼ���������������\n";
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
        cout<<"�쳣������ѡ�޿γɼ���������������\n";
        return false;
    }
    return true;
}

