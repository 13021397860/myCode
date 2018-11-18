#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string="untitled",const int=0);
        ElectiveCourse(ElectiveCourse &);
        virtual ~ElectiveCourse();
        void SetMark(const char);
        virtual int getScore();
        char getMark();
    protected:

    private:
        char mark;
};

#endif // ELECTIVECOURSE_H
