#include "myexception.h"
#include<iostream>
#include<cstdlib>
using namespace std;

MyException::MyException()
{
    da=0;
    ob=0;
    el=0;
    st=0;//ctor
}

void MyException::excDate(Date dt)
{
    try
    {
        if(dt.getYear()<0||dt.getMonth()<1||dt.getMonth()>12||dt.getDay()<0||dt.getDay()>dt.maxDay())
        {
            throw MyException();
        }
    }catch(MyException){
        system("cls");cout<<"\n   日期输入错误\n"<<endl;
        da=1;
        system("pause");
    }
}

void MyException::excCrsO(int cs)
{
    try
    {
        if(cs<0||cs>100)
        {
            throw MyException();
        }
    }catch(MyException){
        system("cls");cout<<"\n   成绩输入错误\n"<<endl;
        ob=1;
        system("pause");
    }
}

void MyException::excCrsE(char cs)
{
    try
    {
        if(cs>'E'||cs<'A')
        {
            throw MyException();
        }
    }catch(MyException){
        system("cls");cout<<"\n   成绩输入错误\n"<<endl;
        el=1;
        system("pause");
    }
}

void MyException::excStd(int sd)
{
    try
    {
        if(sd>=10)
        {
            throw MyException();
        }
    }catch(MyException){
        system("cls");cout<<"\n   课程已满\n"<<endl;
        st=1;
        system("pause");
    }
}

MyException::~MyException()
{
    //dtor
}

MyException::MyException(const MyException& other)
{
    //copy ctor
}
