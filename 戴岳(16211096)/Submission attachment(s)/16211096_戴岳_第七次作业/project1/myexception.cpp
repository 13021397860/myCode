#include "myexception.h"
#include <iostream>
using namespace std;
MyException::MyException()
{
   a="�������ڴ���";
   b="�����Ŵ���";
   c="����ɼ�����";

   error=1;
}

MyException::MyException(int e)
{
   a="�������ڴ���";
   b="�����Ŵ���";
   c="����ɼ�����";

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
