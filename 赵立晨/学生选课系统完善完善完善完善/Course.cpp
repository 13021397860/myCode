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
//    cout<<"�γ���:(δ֪) "<<getName()
//        <<"  ѧ��: "<<getCreditHour()
//        <<"  �÷�: "<<getScore();
//};
ostream &operator <<(ostream &out,const Course &A)
{
     out<<"�γ���: "<<A.getName()
        <<"  ѧ��: "<<A.getCreditHour();
    if (A.getScore()!=-1)
     out<<"  �÷�: "<<A.getScore();
    else
     out<<"  δ���õ÷�!";
    return out;
}
