#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include <iostream>
#include "Course.h"
using namespace std;

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(string = "none",double = 0,int = 1,double = -1);
        virtual ~ObligatoryCourse();
        void setScore(double m);
        double getScore();
    protected:

    private:
        double mark;
};

#endif // OBLIGATORYCOURSE_H
