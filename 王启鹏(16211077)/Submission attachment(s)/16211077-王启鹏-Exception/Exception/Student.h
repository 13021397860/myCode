#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include <bits/stdc++.h>
#include <typeinfo>

#define MAX_SIZE 10
using namespace std;

class Student
{
    public:
        Student(const char * const, const int, const int, const int);
        Student(const  Student &s);
        virtual ~Student();

        void setName(const char *c);
        char *getName();
        Date getBirthDate()const;
        int getCount()const{ return Count; }
        int getCourseNumber()const{ return courseNumber; }
        void print();

        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName, int creditHour);
        bool removeCourse(int);
        const Course& operator[](int)const;
        Course& operator[](int);
        double calcCredit() const;
        friend ostream& operator<<(ostream &, const Student &);

    protected:

    private:
        char *name;
        const Date birthDate;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        static int Count;
        double GetOcCredit() const;
        double GetEcNumber() const;
};

#endif // STUDENT_H
