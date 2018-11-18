#ifndef STUDENT_H
#define STUDENT_H
#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include<cstring>
#include<iostream>
#define MAX_SIZE 200
using namespace std;
class Student
{
    friend class Console;
    friend ostream &operator<<(ostream &, const Student &);
    public:
        Student(const char* const &, int &, int &, int &);
        Student(const Student &s);
        Student(const char* const n, const Date &date);
        void setName(const char* const n);
        const Date& getBirthDate() const {return birthDate;}
        const char* getName() const{return name;}
        void print() const;
        int getScore(int num)const;
        int getCredit();
        static const int getCount(){return count;}
        virtual ~Student();
        double calcCredit();
        Student& addCourse(Course *&course);
        Student& addCourse(const string &courseName, int creditHour);
        void printName() const;
        bool removeCourse(int i);
        const int getCourseNumber()const {return courseNumber;}

    protected:

    private:
        char* name;
        const Date birthDate;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        static int count;
};

#endif // STUDENT_H
