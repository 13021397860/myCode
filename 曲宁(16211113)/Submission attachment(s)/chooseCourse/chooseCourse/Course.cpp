#include <iomanip>
#include "Course.h"

Course::Course(const string& nname,int h)
{
    courseName=nname;
    creditHour=h;
}

void Course::setCoursename(const string &cName)
{
    courseName=cName;
}

void Course::setHour(int h)
{
    creditHour=h;
}

string Course::getcourseName()const
{
    return courseName;
}

int Course::getHour()const
{
    return creditHour;
}

ostream &operator<<(ostream &output,const Course &c)
{
    output<<"CourseName:"<<c.courseName<<"\t"<<"CreditHour:"<<c.creditHour<<"\t"<<"Grade:"<<c.getScore()<<endl ;
    return output;
}


Course::~Course()
{

}
