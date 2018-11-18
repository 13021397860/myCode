#include "Course.h"
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

ostream& operator <<(ostream& o,const Course& a)  //（如果是>>则不能加const，因为要修改值）
{
        o<<"课程名： "<<a.getClassName()<<" 学分: "<<a.getCreditHour()<<" 分数： "<<a.getScore();
        return o;//(为了可以连续输出）
}
