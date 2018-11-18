#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<fstream>
#include "../Course.h"
#include "../Stu.h"
#include "../Time.h"
#include "../ElectiveCourse.h"
#include "../ObligatoryCourse.h"
#define MAX_SIZE 12
using namespace std;
#ifndef CONSOLE_H
#define CONSOLE_H


class Console
{
    public:
        Console();
        virtual ~Console();
        int run();

    protected:

    private:
        Course* selectCourse();
        int displayMenu() const;
        Console& buildStudent();
        Console& buildCourse();
        Console& file_buildStudent(const char*);
        bool infile(const char*);
        bool file_outstudent(const char*,Stu*);

        Console& file_buildcourse(int,string,int);
        bool setCourseScore();
        Stu* s;
        Course* oc[MAX_SIZE];
        Course* ec[MAX_SIZE];
        int ocNum=0;
        int ecNum=0;

};

#endif // CONSOLE_H
