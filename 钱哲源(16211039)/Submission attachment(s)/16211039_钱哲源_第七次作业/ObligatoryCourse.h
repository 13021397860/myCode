#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include<iostream>
using namespace std;

class ObligatoryCourse:public Course
{

    public:
        ObligatoryCourse(const string &n="",int h=0,int m=0):Course(n,h), mark(m){};
        ObligatoryCourse(const ObligatoryCourse& oc):Course(oc),mark(oc.mark){};
        virtual int getScore() const {return mark;};
        void setMark(int m);
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H

