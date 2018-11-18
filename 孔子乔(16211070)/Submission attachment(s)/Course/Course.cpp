#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<iostream>
#include<cstdio>
#include<iomanip>

using std::ostream;
using std::left;
using std::setw;
using std::cout;

Course::Course()
{
    Name="NULL";
    CreditHour = -1;
}

Course::Course(const string _name, const int _credithour)
{
    Name = _name;
    CreditHour = _credithour;
}

Course::Course(const Course &another)
{
    Name = another.Name;
    CreditHour = another.CreditHour;
}

void Course::setname(const string _name)
{
    Name = _name;
}

void Course::setname(const char* _name)
{
    Name = _name;
}

void Course::setcredithour(const int _credithour)
{
    CreditHour = _credithour;
}

void Course::clearcourse()
{
    Name.clear();
    CreditHour = -1;
}

string Course::getname()const
{
    return Name;
}

int Course::getcredithour()const
{
    return CreditHour;
}

ostream& operator<<(ostream& output, Course& course)
{
    output<<string("课程名：")<<setw(20)<<left<<course.Name<<string("学分：")<<setw(25)<<left<<course.CreditHour<<string("性质：");
    Course* tp = &course;
    if(dynamic_cast<ObligatoryCourse*>(tp)!=NULL)output<<string("必修课");
    else output<<string("选修课");
    output<<string("     成绩：");
    if(course.getscore()==-1)output<<string("未设置\n");
    else output<<course.getscore()<<"\n";
    return output;
}

void Course::old_out()const
{
    cout<<string("课程名：")<<setw(20)<<left<<Name<<string("学分：")<<setw(25)<<left<<CreditHour;
    return;
}

Course::~Course()
{
    // nothing needs to be done here.
}
