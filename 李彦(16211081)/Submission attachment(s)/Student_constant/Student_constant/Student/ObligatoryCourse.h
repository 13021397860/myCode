#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"course.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
using std::cin;
class ObligatoryCourse:public course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(string ,int ,int );
        virtual ~ObligatoryCourse();
        void set_(string, int , int );
        int getMark();
        void print();
        void setChengji(int ,char );
        virtual int getScore() const ;
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
