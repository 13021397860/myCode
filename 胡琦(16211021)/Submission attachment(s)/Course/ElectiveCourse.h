#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        int getScore() const;
        void setScore(const int);
        virtual ~ElectiveCourse();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
