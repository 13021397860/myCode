#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#define MAX_SIZE 20
#include "Date.h"
#include <typeinfo>
#include "../Exception/MyException.h"
#include "../Course/Course.h"
class Student
{
    friend ostream& operator<<(ostream &,const Student &);
public:
    Student();
    Student(char *,Date& );
    Student(const Student &);
    virtual ~Student();
    char* getName()const;
    Date getBirthDate()const;
    void setName(const char *N);
    void print()const;
    void setBirthDaty(Date &d){birthDate=d;}
    int getCourseNumber()const{return courseNumber;}
    static int getCount();
    bool removeCourse(int);
    double calcCredit()const;
    Course* getcourse(int i)const{if(i<1||i>courseNumber)throw MyException(RANGE_ERROR); else return courseList[i];}
    Student &addCourse(Course *course);
    //Student &addCourse(const std::string &courseName,int creditHour);
private:
    static int count;
    char *name;
    Date birthDate;
    Course *courseList[MAX_SIZE];//save from 1
    int courseNumber=0;
};


#endif //STUDENT_STUDENT_H
