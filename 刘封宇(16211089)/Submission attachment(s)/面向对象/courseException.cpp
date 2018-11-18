#include  <iostream>
#include "courseException.h"
using namespace std;

CourseException::CourseException()
{
    message=new char[1000];

}

CourseException::CourseException(char *str)
{
    message=str;
}

bool CourseException::CourseExceptionCheck(int a)
{
    try
    {
        if(a<0||a>100)
        throw a;
    }
    catch(int a)
    {
        cout<<"输入必修课成绩错误，请重新输入!"<<endl;
        return false;
    }
    return true;
}

bool CourseException::CourseExceptionCheck(char a)
{
    try
    {
        if(a<'A'||a>'E')
            throw a;
    }
    catch(char a)
    {
        cout<<"输入选修课成绩错误，请重新输入!"<<endl;
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
