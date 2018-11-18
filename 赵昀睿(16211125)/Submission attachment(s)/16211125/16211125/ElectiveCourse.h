#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include "IllegalGrade.h"

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse(string n,int c,char m);
        virtual ~ElectiveCourse();
        //
        void setGrade(char g);
        int getScore()const;
        void printScore()const;

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
