#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include <iostream>
#include<typeinfo>

using namespace std;

class console
{
    public:
        console();
        virtual ~console();
        void setCourseScore();
        Course* selectCourse(int);
        console& student();
        console& course();
        int menu();
        int run();

    protected:

    private:
        Student *student1;
        Course *OC[MAXSIZE];
        Course *EC[MAXSIZE];
        int ocNum,ecNum;
};

#endif // CONSOLE_H
