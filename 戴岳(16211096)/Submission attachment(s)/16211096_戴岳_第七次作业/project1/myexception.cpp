#include "myexception.h"
#include <iostream>
using namespace std;
MyException::MyException()
{
   a="输入日期错误！";
   b="输入编号错误！";
   c="输入成绩错误！";

   error=1;
}

MyException::MyException(int e)
{
   a="输入日期错误！";
   b="输入编号错误！";
   c="输入成绩错误！";

   error=e;
}
void MyException::what()const
{
    if(error==1)
    {
        cout<<a<<endl;
    }
    else if(error==2)
    {
        cout<<b<<endl;
    }
    else if(error==3)
    {
        cout<<c<<endl;
    }

}

MyException::~MyException()
{
    //dtor
}
