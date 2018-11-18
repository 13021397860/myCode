#include <iostream>
using namespace std;
#include "Course.h"

#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
class ElectiveCourse :public Course
{
private:
    char grade;
public:
    void setMark(char g){grade=g;}
    virtual int getScore()const;
    ElectiveCourse(string n="NoFound",int c=0,char g='E');
//    ElectiveCourse(Course c,char g);
    void CoursePrint()const;
    ~ElectiveCourse(){}
};

#endif // ELECTIVECOURSE_H
