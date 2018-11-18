#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include <iostream>
#include "Course.h"
using namespace std;

class ElectiveCourse:public Course
{
    public:
        int tag=2;
        ElectiveCourse(string A,double cH,int = 2,char = 'F');
        virtual ~ElectiveCourse();
        void setScore(char s);
        double getScore();
        int Tag(){return tag;}
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
