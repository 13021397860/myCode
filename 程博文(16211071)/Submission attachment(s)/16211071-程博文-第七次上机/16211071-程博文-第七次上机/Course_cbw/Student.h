#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#define MAX_SIZE 21

class Student
{
public:
    Student();
    Student(const char* const p,const int &y,const int &m,const int &d);
    Student(const Student &t);
    virtual ~Student();
    char* getName();
    void setName(const char* const q);
    void setbirthDate(const int &y,const int &m,const int &d);
    Date getbirthDate();
    static int getCount();
    Student& addCourse(Course *course);
    Course* getCourse(const int i);
    int getCourseNumber();
    friend ostream & operator <<(ostream &os,const Student&s);
    bool removeCourse(int i);
    double calcCredit();

protected:

private:
    static int count;
    char* name;
    Date birthDate;
    Course* courseList[MAX_SIZE];
    int courseNumber;
};

#endif // STUDENT_H
