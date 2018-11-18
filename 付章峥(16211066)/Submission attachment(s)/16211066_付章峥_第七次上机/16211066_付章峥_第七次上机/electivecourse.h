#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "course.h"
#include<iostream>
#include<string>

using namespace std;

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse(const string ="NoCourse",const int =0,const char =0);
        void setElectiveCourse(const string ="NoCourse",const int =0,const char=0);
        void setGrade(const char =0);
        virtual int getScore()const;
        char getGrade()const;
        ElectiveCourse(const ElectiveCourse& other);
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
