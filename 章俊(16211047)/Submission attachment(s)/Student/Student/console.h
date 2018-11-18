#ifndef CONSOLE_H
#define CONSOLE_H

#include "student.h"
#include "time.h"
#include <iostream>
#include <cstring>
#include "course.h"
#include "student.h"
#include <string>
#include "obligatorycourse.h"
#include "electivecourse.h"
#include <fstream>


#define MAX_SIZE 10
using namespace std;
using std::ostream;
using std::istream;

class Console
{
    public:
        int run();
        Console();
        virtual ~Console();

    private:
        int displayMenu()const;
        void selectObCourse();
        void selectElCourse();
        void removecourse();
        bool setCourseScore();
        void buildStudent();
        void buildCourse();
        bool save();
        Student *student1;
        ObligatoryCourse *ob[MAX_SIZE];
        ElectiveCourse *el[MAX_SIZE];
};

#endif // CONSOLE_H
