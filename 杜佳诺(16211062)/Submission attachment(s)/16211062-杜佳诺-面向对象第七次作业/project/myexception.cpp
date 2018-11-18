#include <exception>
#include <iostream>
#include "myexception.h"
#include "Date.h"

MyException::MyException(string s)
:str(s)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

bool MyException::DateException( int year, int month, int day )
{
    string str="Illegal Date Information\n";
    try
    {
    if( year<=0 || month<1 || month>12 || (((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31))|| ((month==4||month==6||month==9||month==11)&&day>30) || ((year%4!=0||(year%100==0&&year%400!=0))&&day>28) || (((year%4==0&&year%100!=0)||year%400==0)&&day>29))
    throw MyException(str);
    }
    catch(MyException&)
    {
        cout<<str;
        return false;
    }
    return true;
}

bool MyException::CourseListException( int x, int coursenumber )
{
    string str="Illegal Array Visit\n";
    try
    {
        if(x>coursenumber)
            throw MyException(str);
    }
    catch(MyException&)
    {
        cout<<str;
        return false;
    }
    return true;
}

bool MyException::OcSetGradeException( int x )
{
    string str="Illegal Grade, please input again( 0 - 100 )\n";
    try
    {
        if(x>100||x<0)
            throw MyException(str);
    }
    catch(MyException&)
    {
        cout<<str;
        return false;
    }
    return true;
}

bool MyException::EcSetGradeException( char x )
{
    string str="Illegal Grade, please input again( A - E )\n";
    try
    {
        if(x>'E'||x<'A')
            throw MyException(str);
    }
    catch(MyException&)
    {
        cout<<str;
        return false;
    }
    return true;
}
