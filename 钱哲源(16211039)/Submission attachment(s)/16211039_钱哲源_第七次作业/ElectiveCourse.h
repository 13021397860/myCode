#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include<iostream>
using namespace std;


class ElectiveCourse: public Course
{
    public:
        ElectiveCourse(const string &n="",int h=0,char g='\0'):Course(n,h),grade(g){};
        ElectiveCourse(const ElectiveCourse& ec):Course(ec),grade(ec.grade){};
        virtual int getScore() const;
        void setGrade(char g);
        virtual ~ElectiveCourse();
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
