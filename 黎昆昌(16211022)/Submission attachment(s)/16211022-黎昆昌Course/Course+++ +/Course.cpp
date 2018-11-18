#include "Course.h"
#include<iomanip>
Course::Course(const string s,const int n)
{
    setName(s);
    setCreditHour(n);
}

void Course::setName(const string &s)
{
    name=s;
}

string Course::getName() const
{
    return name;
}

void Course::setCreditHour(const int &n)
{
    creditHour=n;
}

int Course::getCreditHour() const
{
    return creditHour;
}

void Course::setScore(const int &s){}

//int Course::getScore() const {return -1;}

ostream &operator<<(ostream &output,const Course &course)
{
    output<<"CourseName:"<<left<<setw(10)<<course.getName()<<
            "Credit:"<<left<<setw(3)<<course.getCreditHour()<<
            "Score:";
    if(course.getScore()==0){
        output<<"none";
    }
    else{
        output<<left<<setw(3)<<course.getScore();
    }
    return output;
}

Course::~Course()
{
    //dtor
}
