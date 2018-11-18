#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "course.h"
#include<iostream>
#include<string>

using namespace std;

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(const string ="NoCourse",const int =0,const int =0);
        void setObligatoryCourse(const string ="NoCourse",const int =0,const int =0);
        void setMark(const int =0);
        virtual int getScore()const;
        ObligatoryCourse(const ObligatoryCourse& other);
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
