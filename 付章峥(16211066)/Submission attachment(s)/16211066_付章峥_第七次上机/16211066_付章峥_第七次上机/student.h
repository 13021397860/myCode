#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include "course.h"
#include<iostream>
#include "myexception.h"

#define MAX_SIZE 10

class Student
{
    public:
        Student(const char*const ="Noname",const int =1,const int =1,const int =2000);
        Student(const Student& other);
        void setName(const char*const);
        char* getName();
        void setBirthDate(const int =1,const int =1,const int =2000);
        Date& getDate();
        int getBirthMonth();
        int getBirthDay();
        int getBirthYear();
        static int getCount();
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName,const int creditHour);
        int getcourseNumber();
        string getcourseName(int);
        bool removeCourse(int);
        void setgrade(int);
        const Course& operator[](int);
        int bac[MAX_SIZE];
        void newG();
        friend ostream &operator<<(ostream &,const Student &);
        virtual ~Student();
        bool OoE;
        MyException e;

    protected:

    private:
        char*name;
        Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        double calcCredit;

};

#endif // STUDENT_H
