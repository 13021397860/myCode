#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string n="", const int ch=0):Course(n, ch){}
        void setGrade(const char);
        virtual int getScore() const;
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
