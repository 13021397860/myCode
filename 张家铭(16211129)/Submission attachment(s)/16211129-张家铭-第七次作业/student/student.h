#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#define MAX_SIZE 10
#include "date.h"
#include "course.h"
#include "electiveCourse.h"
#include "obligatoryCourse.h"
#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    char *name;
    const date birthDate;
    static int count;
    int courseNumber=0;
    course *courseList[MAX_SIZE];
public:
    //course *courseList[MAX_SIZE];
    student &addCourse(course *course);
    //student &addCourse(const string &,const int );
    bool removeCourse(int );
    bool removeCourse(const string );
    student(const char *,const date&);
    student(const student &);
    virtual ~student();
    const char *getName() const;
    const date getBirthDate() const;
    void setName(const char *);
    void getInformation() const;
    static int getCount();
    void print() const;
    int getNumber() const;
    float calcCredit();
    void setFenshu();
    void getCourseList(int i,course *&temp);
    course *getCourse(int i);
    friend ostream &operator<<(ostream &,const student &);
};


#endif // STUDENT_H_INCLUDED
