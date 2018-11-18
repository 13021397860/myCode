#ifndef STUDENT_H
#define STUDENT_H

#include "date.h"
#include<string>
#include"ObligatorayCourse.h"
#include"ElectiveCourse.h"

#define MAX_SIZE 51

using namespace std;
class Student
{

    public:
        Student(char* const s="Tom",const int y=1998,const int m=1,const int d=1);
        Student(Student const &);
        virtual ~Student();
        void Set( char* const, int ,int ,int );
        void get_name(char *&) const;
        void get_birthday( Date & ) const;
        void print();
        static int getCount();
        virtual Student& addCourse(Course *course);
        bool removeCourse(int);
        Course *courseList[MAX_SIZE];
        int courseNumber;
        friend ostream &operator << (ostream &,const Student&);
        double calcCredit();
    protected:

    private:
        char *name;
        Date birthdate;
        static int count_stu;

};

#endif // STUDENT_H
