#ifndef STUDENT_H
#define STUDENT_H
#include "Course.h"
#define MAX_SIZE 10
#include <iostream>
#include <cstring>
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include <typeinfo>

class Student
{
    friend ostream& operator<<(ostream& , Student& );
    public:
        Student(const char *const s="", const int y=1, const int m=1, const int d=1);
        Student(const Student &s);
        char * getName() const;
        Date getBirthDate() const;
        static int getCount();
        int getCourseNumber();
        void setName(const char *const);
        void setGrade(const int i);
        void printCourse() const;
        Student &addCourse(Course *);
        Student &addCourse(const string , int );
        bool removeCourse(int );
        bool selected(const Course *) const;
        double calcCredit() const;
        virtual ~Student();

    protected:

    private:
        char *name;
        const Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};



#endif // STUDENT_H
