#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#include "Course.h"

Course::Course()
{
    //ctor
}

Course::Course(const string s, const int c)
{
    setName(s);
    setCreditHour(c);
}

void Course::setCreditHour(const int a)
{
    creditHour = (a >= 0) ? a : 0;//如果输入的学分为负数，将其学分设为0
}

void Course::setName(const string _name)
{
    if(_name!="\0")
        name = _name;
    else
        name = "no course";
    //如果输入的名字为空，将课程名设为no course
}

void Course::setKind(const int k)
{
    kind=k;
}
void Course::setScore(const int)
{

}

/*int Course::getScore() const
{
    return getScore();
}*/

Course::~Course()
{

}

ostream& operator<<(ostream& output, const Course& c)
{
    output<<"课程名："<<c.name<<"  学分："<<c.creditHour;
    return output;
}
