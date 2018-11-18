#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"course.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
using std::cin;
class ElectiveCourse:public course
{
    public:
        ElectiveCourse();
        ElectiveCourse(string ,int ,char );
        virtual ~ElectiveCourse();
        void set_(string ,int ,char );
        char getEGrade();
        void print();
        void setChengji(int ,char );
        virtual int getScore() const ;
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
