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
        void setMark(int grade);//set函数，设置成绩
        const int getMark()const{return mark;}//get函数，返回mark值
        virtual ~ObligatoryCourse();
        void print() const;

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
