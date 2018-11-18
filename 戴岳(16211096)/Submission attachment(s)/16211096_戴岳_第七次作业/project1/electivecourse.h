#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<iostream>
#include"course.h"
using namespace std;

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string ,const int);
        ElectiveCourse(const string ,const int, const char);

        void setScore(const char);
        int getScore()const;


        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
