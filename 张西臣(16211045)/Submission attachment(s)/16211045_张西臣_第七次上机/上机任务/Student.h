#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#define MAX_SIZE 3
#include <iostream>
using namespace std;
class Student
{
    public:
        Student();
        Student(const Student &n);
        void setname(const char *n);
        void setbirthDate(int y,int m,int d);
        char* getname()const;
        int getbirthDateyear()const;
        int getbirthDatemonth()const;
        int getbirthDateday()const;
        int getcourseNumber()const;
        void setcourseNumber();
        bool setCourseScore(int);
        static int getCount();
        friend ostream& operator<<(ostream& output, const Student& s);
        /*Course * operator [](int i)
        {
            return courseList[i];
        };*/
        const Course& operator[](int subscript) const;
        void sprint(Student &stu)const;
        Student& addcourse(Course *course);
        Student& addcourse(const string& coursename,int credithour);
        bool removeCourse(int i);
        virtual~Student();
        int courseNumber;
        double calcCredit();
        bool inscoretf(int m);
        bool inscoretf(char c);
    private:
        char *name;
        Date birthDate;
        int length;
        static int Scount;
        Course *courseList[MAX_SIZE];
        int marks;
        char grades;
};

#endif // STUDENT_H
