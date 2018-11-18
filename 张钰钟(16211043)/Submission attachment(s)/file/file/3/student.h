#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include"course.h"
const int MAX_SIZE=10;
class Student
{
    public:
        Student();
        Student(const Student&);
        virtual ~Student();
        void setStudentName(const char*);
        void setStudentBirthDate(int,int,int);
        int getStudentBirthYear();
        int getStudentBirthMonth();
        int getStudentBirthDay();
        char* getStudentName();
        static int getCount();
        void printBirthDate();
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName, int creditHour);
        void print();
        //Student operator << (int);
        bool removeCourse(int i);
        void fen(string tarname,int *x);
        void fen(string tarname,char *x);
        Course *courseList[MAX_SIZE];
        double calcCredit();
        int courseNumber=0;int obno=0;
    protected:
    private:
        char *name;
        Date birthDate;
        static int count;
        //Course *courseList[MAX_SIZE];
        //int courseNumber=0;

};

#endif // STUDENT_H
