#ifndef CONSOLE_H
#define CONSOLE_H
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<cstring>
class Console
{
    public:
        Console();
        virtual ~Console();
        void create();
        void choose();
        void setScore();
        bool control();
        void PPtest();
    private:
        Student *temp;
        std::string x;
        int y,d,m,score,credit;
        char c[100],grade;
};
#endif
