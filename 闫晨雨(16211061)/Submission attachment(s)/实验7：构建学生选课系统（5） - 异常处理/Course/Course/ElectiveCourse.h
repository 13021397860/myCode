#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string s, const int h, const char c = 'E');
        virtual ~ElectiveCourse();
        int setGrade(const char c);
        virtual int getScore()const;
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
