#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string n, const int c, const char g)
    :Course(n, c), grade('F')
{
    //setGrade(g);
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(const char g)
{
    if(g>='A' && g<='E')
        grade=g;
    else{
        MyException except("grade");
        throw except;
    }
    return ;
}

double ElectiveCourse::getScore() const//virtual
{
    if(grade=='A')          return 95;
    else if(grade=='B')     return 85;
    else if(grade=='C')     return 75;
    else if(grade=='D')     return 65;
    else if(grade=='E')     return 55;
    else                    return 0;
}

void ElectiveCourse::print() const
{
    cout<<"课程："<<getName()<<"\t学分："<<getCreditHour()<<"\t成绩："<<getScore()<<endl;
    return ;
}

double ElectiveCourse::getWeight() const//virtual
{
    return 0.4;
}
double ElectiveCourse::getCreditHour() const//virtual
{
    return 0;
}
