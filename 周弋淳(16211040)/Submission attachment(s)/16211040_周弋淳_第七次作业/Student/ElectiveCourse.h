#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string n="none",const int c=0):Course(n,c){};
        void setGrade(const char);
        int getScore() const;
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
