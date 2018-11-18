#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include "MyException.h"
#include<iostream>
using namespace std;


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string="", const int=0, const char='F');
        virtual ~ElectiveCourse();
        void setGrade(const char='F');

        virtual double getCreditHour() const;
        virtual double getScore() const ;
        virtual double getWeight() const ;
        void print() const ;

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
