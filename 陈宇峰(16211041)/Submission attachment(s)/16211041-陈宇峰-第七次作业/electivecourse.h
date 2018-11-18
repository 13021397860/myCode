#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
using namespace std;

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        void setgrade(const char);
        virtual int getScore() const;

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
