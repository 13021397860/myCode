#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        virtual ~ElectiveCourse();
        virtual void setGrade(const char);
        int getScore();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
