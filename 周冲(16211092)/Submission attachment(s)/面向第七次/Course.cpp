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
        o<<"课程名： "<<a.getClassName()<<" 学分: "<<a.getCreditHour()<<" 分数： "<<a.getScore();
        return o;
}
