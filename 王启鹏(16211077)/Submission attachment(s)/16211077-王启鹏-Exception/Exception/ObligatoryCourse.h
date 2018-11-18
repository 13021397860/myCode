#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include "MyException.h"
#include<iostream>
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string="", const int=0, const int=0);
        virtual ~ObligatoryCourse();
        void setMark(const int=0);

        virtual double getNumber() const;
        virtual double getScore() const ;
        virtual double getWeight() const ;
        void print() const ;
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
