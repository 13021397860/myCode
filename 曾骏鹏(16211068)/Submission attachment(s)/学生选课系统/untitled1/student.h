//
// Created by zjp on 2017/4/17.
//
#include <iostream>
#include "date.h"
#include "course.h"
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 7
using namespace std;

class student {
public:
    student();
    student(const char *n,const int y,const int m,const int d);
    student(const student &s);
    ~student();
    const char* getName(void) const;
    void setName(const char * const n);
    void printName() const;
    int getCount(void) const;
    int getNumber() const;
    void printBirthDate(void) const;
    student& addCourse(course *course);
    //student& addCourse(const string &courseName,const int creditHour);
    void printBasicInfo() const;
    bool removeCourse(const int);
    bool setCourseScore();
    double calcCredit() const;
    void printInfo(student &s) const;
    friend ostream& operator << (ostream &os,const student &s);
private:
    char *name;
    const date birthDate;
    static int count;
    course *courseList[MAX_SIZE];
    int courseNumber;
};


#endif //UNTITLED1_STUDENT_H
