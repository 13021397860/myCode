#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
Course::Course()
{
    //ctor
};
Course::Course(const Course &other)
{
    name=other.getName();
    creditHour=other.getCreditHour();
};
Course::Course(const string& _name,int _creditHour)
{
    name=_name;
    creditHour=_creditHour;
};
Course::~Course()
{
    //dtor
}
bool Course::setName(const string& _name)
{
    name=_name;
    return 0;
}
bool Course::setCreditHour(int _creditHour)
{
    creditHour=_creditHour;
    return 0;
}
const string& Course::getName()const
{
    return name;
}
int Course::getCreditHour()const
{
    return creditHour;
}
//void Course::printCourse()const
//{
//    cout<<"课程名:(未知) "<<getName()
//        <<"  学分: "<<getCreditHour()
//        <<"  得分: "<<getScore();
//};
ostream &operator <<(ostream &out,const Course &A)
{
     out<<"课程名: "<<A.getName()
        <<"  学分: "<<A.getCreditHour();
    if (A.getScore()!=-1)
     out<<"  得分: "<<A.getScore();
    else
     out<<"  未设置得分!";
    return out;
}
