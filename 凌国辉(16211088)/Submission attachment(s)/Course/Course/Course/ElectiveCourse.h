#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include<typeinfo>
#include"Course.h"
#include"MyException.h"
using namespace std;

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(string a,int b,char c='A'):Course(a,b){grade=c;}
        virtual ~ElectiveCourse();
        void setGrade()
        {
            char a;cin>>a;
            if(a<'A'||a>'E')
            {
                throw MyException();
            }
            grade=a;
        }
        int getScore()const{return 95-(grade-'A')*10;}
        void printClass()
        {cout<<className<<" "<<creditHour<<" "<<grade<<endl;}

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
