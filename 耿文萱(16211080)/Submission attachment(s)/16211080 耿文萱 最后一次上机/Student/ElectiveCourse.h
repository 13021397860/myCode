#include "Course.h"
#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include <string>
#include <iostream>
using namespace std;


class ElectiveCourse: public Course
{
    public:
        ElectiveCourse(const string &,const int ,const char ='0');
        void setGrade(const int ,const char );
        virtual int getScore()const;
        void print1();
        virtual int getO() const {return 0;}
        virtual ~ElectiveCourse();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
