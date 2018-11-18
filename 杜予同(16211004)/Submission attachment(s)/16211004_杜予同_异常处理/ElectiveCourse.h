#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(int ch=0,string nam="self-taught Class",int s='F');
        virtual ~ElectiveCourse();
        void setscore(int s);
        int getscore();
        void toString()
        {
            cout<<name<<" "<<creditHour<<" "<<getscore();
        }
    protected:
    private:
        char sorce;
};

#endif // ELECTIVECOURSE_H
