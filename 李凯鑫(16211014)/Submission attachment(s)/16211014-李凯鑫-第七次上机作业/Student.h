#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include<iostream>
using namespace std;

#define MAX_SIZE 11

class Student
{
public:
    Student(const char *, int,int, int);
    virtual ~Student();
    Student(Student &s);
    void setStudent(const char*, int, int, int);
    char* getName()
    {
        return name;
    }
    void checkName();
    static int getCount();
    int getBirthdateYear()
    {
        return birthDate.getYear();
    }
    int getBirthdateMonth()
    {
        return birthDate.getMonth();
    }
    int getBirthdateDay()
    {
        return birthDate.getDay();
    }
    Date getBirthDate(){return birthDate;}
    double getCredit(){return Credit;}
    friend ostream& operator<<(ostream& ,const Student& );
    Student& addCourse(Course *course,string type);
    bool removeCourse(int i);
    void setMark(int, string);
    void calcCredit();
private:
    char *name;
    Date birthDate;
    static int count;
    int OCourseNumber;
    int ECourseNumber;
    Course *courseList[MAX_SIZE];
    int courseNumber;
    double Credit;
};

#endif // STUDENT_H
