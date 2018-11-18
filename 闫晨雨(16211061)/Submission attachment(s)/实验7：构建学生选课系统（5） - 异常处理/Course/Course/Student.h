#ifndef STUDENT_H
#define STUDENT_H
#include "Time.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

#define MAX_SIZE 10

class Student
{
    public:
        //Student();
        Student(const char *const n, const int y1, const int m1, const int d1);
        Student(const Student &a);
        int setName(const char *const n);
        int getName(char *&n)const;
        int getBirthDate(int &y, int &m, int &d)const;
        int print()const;
        int getCount()const;
        Student& addCourse(const Course *const course);
        /*Student& addCourse(const string &courseName, const int creditHour);*/
        bool removeCourse(const int i);
        int setScore();
        virtual ~Student();
        double calcCredit()const;
        int askforScore()const;
    friend ostream& operator <<(ostream &, Student &);
    private:
        char *name;
        const Time birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STUDENT_H
