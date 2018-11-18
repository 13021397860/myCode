#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(char y);
        ElectiveCourse();
        virtual void setGrade(char z);
        virtual int getScore()const;
        virtual int who();
    protected:
        char grade;
};

#endif // ELECTIVECOURSE_H
