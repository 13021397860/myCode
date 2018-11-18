#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "MyException.h"
#include<bits/stdc++.h>
#include<typeinfo>
#include<fstream>
using namespace std;

class Console
{
    public:
        Console();
        virtual ~Console();
        void run();
        void buildStudent();
        void buildCourse();
        int display();
        Course* chooseCourse(int);
        void deleteCourse();
        void setCourseScore();
    protected:

    private:
        Student *person;
        Course *ocList[6];
        Course *ecList[4];
};

#endif // CONSOLE_H
