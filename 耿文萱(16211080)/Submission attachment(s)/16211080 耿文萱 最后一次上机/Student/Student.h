#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 50

#include "Date.h"


class Student
{
    public:
        Student(const char* ,int ,int,int);
        Student(const Student& );
        Student& addCourse(Course *);
        friend ostream& operator << (ostream&,const Student&);
        //Student& addCourse(const string &, int );
        virtual ~Student();
        //void print();
        void setName(const char* n);
        static int getcount();
        int co()const;
        int ce()const;
        char* getname();
        double calcCredit() const;
        bool reCourse(int );
        int gety();
        int courseNumber;
        const Date birthDate;
        Course *courseList[MAX_SIZE];
    protected:
    private:
        char* name;
        //const Date birthDate;
        static int count;
        //Course *courseList[MAX_SIZE];
        //int courseNumber;
};

#endif // STUDENT_H
