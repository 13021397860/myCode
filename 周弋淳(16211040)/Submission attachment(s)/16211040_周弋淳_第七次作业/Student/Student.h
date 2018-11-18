#ifndef STDUENT_H
#define STDUENT_H

#include "Date.h"
#include "Course.h"
#include<iostream>

#define MAX_SIZE 100

using namespace std;

class Student
{
    friend ostream& operator<<(ostream&, const Student&);
    public:
        Student(const char *n="nobody",const int=1,const int=1,const int=1);
        Student(const Student&);
        virtual ~Student();
        char *getName() const;
        Student& setName(const char *const n);
        static int getCount();
        Date getBirthDate() const;
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName,int creditHour);
        void courseListPrint() const;
        bool removeCourse(const int i);
        bool ifCourseAdded(const Course&) const;
        void setCourseGrade(const int i);
        double calcCredit() const;
        int getCourseNumber() const;

    protected:

    private:
        char *name;
        int length;
        const Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STDUENT_H

