//
// Created by zjp on 2017/4/17.
//

#include "course.h"
#include <iostream>
string course::getName() const
{
    return name;
}

int course::getCreditHour() const
{
    return creditHour;
}

void course::setName(const string s)
{
    name=s;
}

void course::setCreditHour(const int c)
{
    creditHour=c;
}

ostream& operator << (ostream &os,const course &c)
{
    os << "课程名：" << c.getName() << " 学分：" << c.getCreditHour();
    os << " 成绩：" << c.getScore();
    return os;
}

course::~course() {}