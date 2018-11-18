#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const char);
        void setGrade(const char);
        int getScore();
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
