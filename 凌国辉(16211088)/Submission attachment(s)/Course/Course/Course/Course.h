#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Course
{
    public:
        Course();
        Course(string x,int y){className=x;creditHour=y;}
        virtual ~Course();
        void setClassName(string a){className=a;}
        string getClassName()const{return className;}
        void setCreditHour(int b){creditHour=b;}
        int getCreditHour()const{return creditHour;}
        virtual void printClass(){}
        friend ostream& operator <<(ostream& o,const Course& a);
        virtual void setGrade(){}
        virtual int getScore()const=0;
    protected:
        string className;
        int creditHour;
    private:

};

#endif
