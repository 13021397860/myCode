#ifndef STUDENT_H
#define STUDENT_H
#include "time.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <typeinfo>
#define MAX_SIZE 10
#define weight_ElectiveCourse 0.4
#define weight_ObligatoryCourse 0.6


class Student
{
    public:
        Student(const char *const ,const int=1900 ,const int=1 ,const int=1 );
        Student (const Student &);
        virtual ~Student();
        void SetName(const char *const );
        void SetBirthDate(const int ,const int ,const int );
        void ShowBasicInformation();
        void ShowSelectedCourse();
        const char* const GetName() const;
        static int GetCount();
        const int Get_courseNumber();
        Student& addCourse(Course *);
        Student& addCourse(Course &);
        //Student& addCourse(ObligatoryCourse *);
        //Student& addCourse(ElectiveCourse *);
        //Student& addCourse(const string ,int );
        Course* getCourse(int );
        bool removeCourse(int );
        friend ostream & operator << (ostream &, Student &);
        float calcCredit();
        void showCalcCredit();
    protected:

    private:
        static int studentCount;
        char* name;
        time birthDate;
        Course* courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STUDENT_H
