#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<iostream>
#include"Course.h"
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(string = "a", int = 0, int = 1);
        virtual ~ObligatoryCourse();
        void setMark(int);
        virtual int getScore();
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
