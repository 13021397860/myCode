#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "course.h"

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse(string="",int=0,char='E');
        ElectiveCourse(const ElectiveCourse& a);
        void setScore(int=0);
        int getScore() {return score[grade-'A'];};
        virtual ~ElectiveCourse();
        static int score[5];
    protected:
        char grade;
    private:
};

#endif // ELECTIVECOURSE_H
