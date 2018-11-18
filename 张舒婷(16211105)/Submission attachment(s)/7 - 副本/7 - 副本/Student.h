#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include"Course.h"
#define MAXSIZE 10
#include <iostream>
using std::ostream;

class Student
{
    friend ostream& operator<<(ostream &,const Student &);
    public:
        Student(const char* const n,int y,int m,int d);//构造函数
        Student(const char *const n,const Date &d);//构造函数
        Student(const Student &s);//拷贝构造函数
        virtual ~Student();

        void print() const;
        Student& setName(const  char* const n);
        const char* getName() const{return name;}
        const Date& getBrithDate() const {return birthDate;}
        int getcourseNumber()const{return courseNumber;}
        static int getCount(){return count;}
        Student& addCourse(Course*course);
        Student& addCourse(const string&courseName,int creditHour );
        bool removeCourse(int);
        bool removeCourse(const string& courseName);
        Course& operator[](int i)const;
        double calcCredit()const;

    protected:

    private:
        char *name;
        const Date birthDate;
        static int count;
        Course* courseList[MAXSIZE];
        int courseNumber;
};

#endif // STUDENT_H
