#include "MyException.h"
#include <iostream>
using namespace std;
MyException::MyException(string s)
{
    message=s;
    //ctor
}

MyException::~MyException()
{
    //dtor
}

void MyException::what(){
    switch(message[8]){
        case 'D':cout<<"\n输入日期信息异常！\n请重新输入！"<<endl;break;
        case 'C':cout<<"\n输入课程编号异常！\n请重新输入！"<<endl;break;
        case 'S':cout<<"\n输入课程成绩异常！\n请重新输入！"<<endl;break;
        default:cout<<"\n未知错误类型！\n请重新输入！"<<endl;break;
    }
}
