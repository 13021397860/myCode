#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

class ElectiveCourse:public  Course
{
    public:
        ElectiveCourse(const string &n="Mathmatic",int ch=0, char g='\0');
        void setxuanxiu(char);
        int getscore();
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
        friend class Student;
};

#endif // ELECTIVECOURSE_H
