#include "MyException.h"
#include "Date.h"
#include "Student.h"
#include<string>

enum TYPE{DATE_EX,COURSENUM_EX,GRADE_EX};
MyException::MyException(int n)
{
    //ctor
    ExceptionType=TYPE(n);
}

MyException::~MyException()
{
    //dtor
}

void MyException::DateException(Date d)
{
    if(d.IsLegalDate()==0)
    {
        throw d;
    }
}

void MyException::CourseNumException(int n,Student *s)
{
    if(s->removeCourse(n)==0)
        throw n;
}

void MyException::GradeException(int grade)
{
    if(grade>100 or grade<0)
        throw grade;
}

void MyException::ThrowException()
{
    switch (ExceptionType)
    {
    case DATE_EX:
        cout<<"wrong date"<<endl;break;
    case COURSENUM_EX:
        cout<<"wrong course"<<endl;break;
    case GRADE_EX:
        cout<<"illegal grade"<<endl;break;
    }
}
