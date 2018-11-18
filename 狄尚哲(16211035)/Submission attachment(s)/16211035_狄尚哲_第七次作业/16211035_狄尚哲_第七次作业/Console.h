#ifndef CONSOLE_H
#define CONSOLE_H
#include"Student.h"
#include"Console.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;
class Console
{
    public:
        Console();
        virtual ~Console();
        void Window();
        void CreateStudent();
        void ChooseCourse();
        void RemoveCourse();
        void SetGrade();
        void printScore() const;

    protected:

    private:
        ObligatoryCourse O_course[10];
        ElectiveCourse E_course[10];
        int maxO, maxE; //课程总数
        Student *s;
        const int sleepTime = 750;

        void Print_ObCourse() const;
        void Print_ElCourse() const;
        bool ReadCourse(); //读入课程信息
        bool Save_Student_Data() const;
        void Exit() const;
};

#endif // CONSOLE_H
