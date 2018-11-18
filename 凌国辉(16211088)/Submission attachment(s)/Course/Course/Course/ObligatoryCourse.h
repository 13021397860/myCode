#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include<typeinfo>
#include"Course.h"
#include"MyException.h"
using namespace std;

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(string a,int b,int c=100):Course(a,b){mark=c;}
        virtual ~ObligatoryCourse();
        void setGrade()
        {
            int a;cin>>a;
            if(a<0||a>100)
            {
                throw MyException();
            }
            mark=a;
        }
        int getScore()const{return mark;}
         void printClass(){cout<<className<<" "<<creditHour<<" "<<mark<<endl;}

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
