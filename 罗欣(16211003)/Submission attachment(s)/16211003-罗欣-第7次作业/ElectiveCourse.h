#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        virtual ~ElectiveCourse();
        void setmark(const int);
        int getScore()const;

    protected:

    private:
        char grade;
        int score;
};

#endif // ELECTIVECOURSE_H
