#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<string>
#include"Course.h"
using namespace std;
class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string &,int =2,char ='A');
        void setgrade(char);
         int getScore();
        void print();
        void setCourse(const string &,int);
        virtual ~ElectiveCourse();

    protected:
            char grade;
    private:
};

#endif // ELECTIVECOURSE_H
