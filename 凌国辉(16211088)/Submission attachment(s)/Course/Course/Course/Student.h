#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
//#include"MyException.h"
#define MAX_SIZE 10
using namespace std;

class Student
{
    public:
        Student();
        Student(const char*,Date);
        Student(const Student&);
        virtual ~Student();
        char* getName()const{return name;}
        Student& setBD (Date D);
        //void setName(const char*);
        Date getBirthDate()const{return birthDate;}
         int getYear()const{return birthDate.getYear();}
         int getMonth()const{return birthDate.getMonth();}
         int getDay()const{return birthDate.getDay();}
        void print()const;
        int GetNumber()const{return number;}
        Student& addCourse(Course *course);
        void printclass()const;
        friend ostream& operator <<(ostream& o,const Student& a);
        bool removeCourse(int i);
        int getCourseNumber(){return courseNumber;}
        Course* getList(int i){return courseList[i];}
        double calcCredit();

    protected:

    private:
        char* name;
        const Date birthDate;
        static int number;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif
