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
        cout<<"������޿γɼ���������������!"<<endl;
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
        cout<<"����ѡ�޿γɼ���������������!"<<endl;
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
