#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string _name,int _creditHour);
        virtual ~ElectiveCourse();
        virtual int getscore() const;
        int setgrade(char );
        int setgrade(int );
    protected:
        char grade;

    private:
};

#endif // ELECTIVECOURSE_H
