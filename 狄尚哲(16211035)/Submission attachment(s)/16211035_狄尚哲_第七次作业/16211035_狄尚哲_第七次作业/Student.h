#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<typeinfo>

#define MAX_SIZE 20

class Student
{
    public:
        Student();
        Student(const char *const, const int, const int, const int); //构造函数
        Student(const char *const, const Date &); //构造函数
        virtual ~Student(); //析构函数
        Student(const Student &); //拷贝构造函数

        const char *getName() const;
        const Date &getBirthDate() const;
        void setName(const char* const);
        static int getCount();
        double calcCredit() const;

        //Course
        const int getCourseNumber() const{return CourseNumber;}
        //选课
        Student& addCourse(Course *course);
       // Student& addCourse(const string &courseName, int creditHour);
        //退课
        bool removeCourse(int i);
        //设置成绩
        bool setGrade(int i);

        //重载<<
        friend ostream& operator <<(ostream &os, const Student &s);
        //重载[]
        Course &operator[](int);
        const Course &operator[](int) const;

    private:
        char *name;
        const Date birthDate;
        static int count;

        Course *courseList[MAX_SIZE];
        int CourseNumber;
        const double ObligatoryCourse_weight = 0.6;
        const double ElectiveCourse_weight = 0.4;

        bool existCourse(Course *c) const;
};

#endif // STUDENT_H
