#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include<iostream>
#include<cstring>
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(int ,const string&,int);
        void setScore(int ,int );
        int print()const;
        virtual int getScore()const;
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
