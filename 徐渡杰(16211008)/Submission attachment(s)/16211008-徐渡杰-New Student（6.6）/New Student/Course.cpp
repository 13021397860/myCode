#include "Course.h"
#include <iomanip>
Course::Course(string A,double cH,int t)
{
    setCourseName(A);
    setCourseCredit(cH);
    tag=t;
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setCourseName(string A)
{
    name=A;
}

void Course::setCourseCredit(double cH)
{
    creditHour=cH;
}


string Course::getCourseName()
{
    return name;
}

double Course::getCourseCredit()
{
    return creditHour;
}

ostream& operator<<(ostream &out,Course &course)
{
    out<<"courseName:"<<setiosflags(ios::left)<<setw(25)<<setfill(' ')<<course.getCourseName()<<" courseCredit:"<<course.getCourseCredit();
    if(course.getScore()!=-1)
        out<<" courseScore:"<<course.getScore();
    out<<endl;
    return out;
}
