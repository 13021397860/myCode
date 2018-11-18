#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string na="Empty",const int credit=0):Course(na,credit)
{
    setgrade('F');
}
        virtual ~ElectiveCourse();
        int setgrade(char g);
        virtual int getScore()const ;
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
