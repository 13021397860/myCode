#include <iostream>
#include <fstream>
using namespace std;
#include "Date.h"
#include "Course.h"
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 6
#define ObliWeight 0.6
#define ElecWeight 0.4

class Student{
    private:
        char* StuName;
        const Date *birthDate;
        int len;
        static int counter;
        Course *courseList[MAX_SIZE];
        int courseNumber;
    public:
        char* getName() const {return StuName;}
        void setName(const char* name);
        /*int getDate_year()const{return birthDate->getYear();}
        int getDate_month()const {return birthDate->getMonth();}
        int getDate_day()const {return birthDate->getDay();}*/
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName, int creditHour);
        void setMark(int i);
        int getcounter(){return counter;}
        bool CourseMax(){return courseNumber==MAX_SIZE;}
        bool CourseEmpty(){return courseNumber==MAX_SIZE;}
        //void StuNamePrint()const{cout<<StuName<<endl;}
       // void StuDatePrint()const{cout<<birthDate;}
        //void StuCoursePrint(int i)const{courseList[i]->CoursePrint();}
       // void StuPrint()const;
        void getCourseScore(int i);
        bool removeCourse(int i);
        Student();
		Student(const char* name,int y,int m,int d);
		Student(const Student &s);
        ~Student();
        friend ostream& operator<<(ostream& os,Student &s);
       // friend fstream& operator<<(fstream& os,Student &s);
        float calCredit()const;
};
#endif // STUDENT_H


