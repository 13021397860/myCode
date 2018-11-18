#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include<iostream>
#include<string>
using namespace std;


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string s, int hour, int m = 0):Course(s, hour),mark(m){};
        virtual int getScore() const;
        void setMark(int grade);//set���������óɼ�
        const int getMark()const{return mark;}//get����������markֵ
        virtual ~ObligatoryCourse();
        void print() const;

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
