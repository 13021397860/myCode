#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const char _grade);
        ElectiveCourse(const ElectiveCourse &another);

        virtual int getscore()const;
        char getgrade()const;
        void setgrade(const char _grade);
        void setgrade(const int _score);

        ~ElectiveCourse();
    private:
        char Grade;
};

#endif // ELECTIVECOURSE_H
