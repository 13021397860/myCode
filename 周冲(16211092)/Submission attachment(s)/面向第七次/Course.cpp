#include "Course.h"
#include<string>
#include<iostream>
#include<cstring>
Course::Course()
{
}
Course::~Course()
{
}
std::ostream&operator<<(std::ostream& o,const Course& a)
{
        o<<"�γ����� "<<a.getClassName()<<" ѧ��: "<<a.getCreditHour()<<" ������ "<<a.getScore();
        return o;
}
