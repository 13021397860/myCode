#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include"Course.h"
#include<iostream>
using namespace std;
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(string,int);
        virtual ~ElectiveCourse();
        char getgrade()const{return grade;}
        void setgrade(char );
        int getScore()const;

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
