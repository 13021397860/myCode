#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        virtual ~ElectiveCourse();
        void setGrade(char _grade);
        virtual int getScore() const;
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
