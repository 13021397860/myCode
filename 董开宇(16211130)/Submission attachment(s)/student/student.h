#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
#include <iostream>
using namespace std;
class student
{
    friend ostream& operator<<(ostream &,student &);
public:
    student();
    student(const student &);
    student(const char*,const Date &);
    char* getName();
    void setName(const char*);
    void print();
    Date getBirthDate()const;
    int getNumber();
    int getCourseNumber();
    void setFenshu();
    student& addCourse(Course *course);
    student& addCourse(const string &courseName, int creditHour);
    bool removeCourse(int);
    void printScore();
    void getCourseList(int i,Course*& temp);
    double calcCredit();
    virtual ~student();
protected:

private:
    char* name;
    const Date birthDate;
    static int StuNumber;
    Course *courseList[MAX_SIZE];
    int courseNumber;
};

#endif // STUDENT_H
