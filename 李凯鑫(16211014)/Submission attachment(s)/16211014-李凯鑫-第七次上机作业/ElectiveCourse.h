#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<iostream>
#include"Course.h"
using namespace std;

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(string = "a", int = 1,string = "A");
        virtual ~ElectiveCourse();
        void setGrade(string);
        virtual int getScore();
    protected:

    private:
        string grade;
};

#endif // ELECTIVECOURSE_H
