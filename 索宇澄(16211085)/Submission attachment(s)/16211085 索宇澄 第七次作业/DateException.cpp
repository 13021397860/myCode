#include "DateException.h"
#include <iostream>
using namespace std;

DateException::DateException()
{
    message=new char[1000];
}

DateException::DateException(char *str)
{
    message=str;
}

bool DateException::DateExceptionCheck(int y,int m,int d)
{
    try
    {
        if(y<=0)
            throw y;
        if(m<1||m>12)
            throw m;
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        {
            if(d<1||d>31)
                throw d;
        }
        else if(m==4||m==6||m==9||m==11)
        {
            if(d<1||d>30)
                throw d;
        }
        else if(m==2)
        {
            if((y%400==0)||(y%100!=0&&y%4==0))
            {
                if(d<1||d>29)
                    throw d;
            }
            else
            {
                if(d<1||d>28)
                    throw d;
            }
        }
    }
    catch(int a)
    {
        cout<<"日期不合法，请重新输入"<<endl;
        return false;
    }
    return true;
}

DateException::~DateException()
{
	
}

DateException::DateException(const DateException& other)
{
   
}

DateException& DateException::operator=(const DateException& rhs)
{
    if (this == &rhs) return *this; 
    return *this;
}
