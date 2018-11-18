#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include"Course.h"
#include<iostream>
using namespace std;
class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(string,int);
        virtual ~ObligatoryCourse();
        void printf()const{cout<<getScore()<<"\n";}
        int getScore() const{return mark;};
        void setMark(int );

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
