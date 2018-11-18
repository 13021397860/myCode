#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include<iostream>

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(std::string, int, int = 60);
        ElectiveCourse(const ElectiveCourse&);
        virtual ~ElectiveCourse();
        virtual int getScore() const;
        virtual void setScore(int);
        virtual bool testObligatory() const;
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
