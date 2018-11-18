#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"


class ElectiveCourse :public Course
{
    public:
        ElectiveCourse(string = "unknown", int = 0);
        ElectiveCourse(const ElectiveCourse&);
        void setScore(int = 0, char = 'E') throw(MyException);
        virtual  int getScore()const;
        const void print();
        virtual ~ElectiveCourse();
    protected:
        char grade;
    private:
};

#endif // ELECTIVECOURSE_H
