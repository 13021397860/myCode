#ifndef CONSOLE_H
#define CONSOLE_H
#include"Course.h"
#include"student.h"
#include "student.h"
#include"date.h"
#include "ElectiveCourse.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include<string.h>
#include<iostream>
using namespace std;
class Console
{
    public:
        void  run();
        Console();
        virtual ~Console();
        int c1;
        int c2;
        double gpa;
        int i,xuefeng[105],chengji[105];
        string kecheng[105];

    protected:

    private:

    student *xuesheng;

};

#endif // CONSOLE_H
