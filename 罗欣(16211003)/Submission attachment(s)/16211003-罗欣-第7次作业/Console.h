#ifndef CONSOLE_H
#define CONSOLE_H
#include "Course.h"
#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include<cstring>
#include<iostream>
#define COURSE_SIZE 4
using namespace std;


class Console
{
    public:
        Console();
        virtual ~Console();
        void run();

    protected:

    private:
        void displayMenue()const;
        Course* seletCourse(int op);
        void setCourseScore();
        Console& buildStudent();
        Console& chooseObligatoryCourse(int);
        Console& chooseElectiveCourse(int);
        Console& buildCourse();
        Student *student;
        Date birth;
        Date d2;
        string str;
        int y,m,d;
        ObligatoryCourse *oc[3];
        ElectiveCourse *ec[3];
        Course *cptr0;
        Course *cptr1;
        int cc;
        string cn;
};

#endif // CONSOLE_H
