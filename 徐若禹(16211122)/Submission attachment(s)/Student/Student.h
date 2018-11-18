#ifndef STUDENT_H
#define STUDENT_H
#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#define MAX_SIZE 6
using namespace std;

class Student
{
        friend ostream &operator<<(ostream &,const Student &);
    public:
        Student(char *,const Date&);
        Student(const Student &);
        void setFlag();
        int getFlag() const;
        void setName(char *);
        char *getName() const;
        static int getCount();
        Student &addCourse(Course *course);
        Student &addCourse(const string &courseName,int creditHour,int mark);
        Student &addCourse(const string &courseName,int creditHour,char grade);
        void addGrade(char);
        void addMark(int);
        void removeCourse(int,Student &);
        double calcCredit(Student &);
        int queryScore(int);
        int getCourseNumber() const;
        Course *getCourseList(int) const;
        virtual ~Student();

    protected:

    private:
        char *name;
        Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        double obSum;
        double elSum;
        static int courseNumber;
        int flag;
};

#endif // STUDENT_H
