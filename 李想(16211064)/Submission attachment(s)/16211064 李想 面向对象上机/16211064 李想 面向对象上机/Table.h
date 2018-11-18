#ifndef TABLE_H
#define TABLE_H
#include "Course.h"
#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <bits/stdc++.h>
using namespace std;


class Table
{
    public:
        Table();
        virtual ~Table();

        void Beginning();

        void Build();

        void run();

        Course *choose(int);

        void withdrawCourse();

        void SetCourseScore();


    protected:

    private:
        Student *st;
        Course *ElectiveCourseList[3];
        Course *ObligatoryCourseList[3];
};

#endif // TABLE_H
