#include  <iostream>
#include "CourseException.h"
using namespace std;

CourseException::CourseException()
{
    message=new char[1000];
}

CourseException::CourseException(char *str)
{
    message=str;
}

bool CourseException::CourseException_check_1(int a)
{
    try
    {
        if(a<0||a>100)
            throw a;
    }
    catch(int s)
    {
        cout<<"输入必修课成绩错误，请重新输入\n";
        return false;
    }
    return true;
}

bool CourseException::CourseException_check_2(char a)
{
    try
    {
        if(a<'A'||a>'E')
            throw a;
    }
    catch(char a)
    {
        cout<<"输入选修课成绩错误，请重新输入\n";
        return false;
    }
    return true;
}

CourseException::~CourseException()
{
    
}

CourseException::CourseException(const CourseException& other)
{
    
}

CourseException& CourseException::operator=(const CourseException& rhs)
{
    if (this == &rhs) return *this; 
    return *this;
}
