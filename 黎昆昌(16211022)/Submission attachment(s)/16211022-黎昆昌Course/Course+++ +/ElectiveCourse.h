#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string="math",const int=4,const int=0);
        virtual ~ElectiveCourse();
        virtual void setScore(const int &);
        virtual int getScore() const;

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
