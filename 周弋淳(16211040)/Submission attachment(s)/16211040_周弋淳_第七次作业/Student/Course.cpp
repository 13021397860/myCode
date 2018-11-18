#include <iostream>
#include "Course.h"
#include "Student.h"

using namespace std;

Course::Course(const string s,const int c,const int i,const int j)
{
    name = s;
    creditHour = c;
    ifCourseScoreSet = i;
    ifCourseAdded = j;
}

void Course::setName(const string s)
{
    name = s;
}

void Course::setCreditHour(const int c)
{
    creditHour = c;
}

string Course::getName() const
{
    return name;
}

int Course::getCreditHour() const
{
    return creditHour;
}

ostream& operator<<(ostream& output, const Course& c)
{
    if(c.getIfCourseScoreSet()==0&&c.getIfCourseAdded()==0)
    {
        output<<"课程名："<<c.name<<"  学分："<<c.creditHour;
        return output;
    }
    else if(c.getIfCourseScoreSet()==0&&c.getIfCourseAdded()==1)
    {
        output<<"课程名："<<c.name<<"  学分："<<c.creditHour<<"  未设置成绩！";
        return output;
    }
    else if(c.getIfCourseScoreSet()==1)
    {
        output<<"课程名："<<c.name<<"  学分："<<c.creditHour<<"  Score:"<<c.getScore();
        return output;
    }
}

bool Course::getIfCourseScoreSet() const
{
    return ifCourseScoreSet;
}

void Course::setIfCourseScoreSet(const int s)
{
    ifCourseScoreSet = s;
}

bool Course::getIfCourseAdded() const
{
    return ifCourseAdded;
}

void Course::setIfCourseAdded(const int s)
{
    ifCourseAdded = s;
}

Course::~Course()
{
    //dtor
}
