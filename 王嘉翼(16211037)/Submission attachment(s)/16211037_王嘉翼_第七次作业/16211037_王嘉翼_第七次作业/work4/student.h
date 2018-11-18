#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 500
class student
{

    public:
        student();
        student(const char* constx);
        student(const student& x);
        ~student();
        void setname(const char *const x);
        char* getname()const ;
        void setBirthDate(const Date &x);
        const Date getBirthDate()const ;
        static int getCounter();
        student& addCourse(Course *course);
        student& addCourse(const string &courseName, int creditHour,int st);
        void printCourse();
        int getcn();
        bool removeCourse(int i);
        friend ostream & operator<<(ostream &out,student &x)
        {
            out<<"Name "<<x.name<<" Birthdate"<<x.birthDate<<",courses are followed:"<<"\n";
            for(int i=1;i<=x.courseNumber;++i)
            {
                out<<(*(x.courseList[i]));
            }
            return out;
        }
        void fen(string tarname,int *x);
        void fen(string tarname,char *x);
        int getfen(string tarname);
        double calcCredit();
    protected:

    private:
        char *name;
        Date birthDate;
        static int counter;
        Course* courseList[MAX_SIZE];
        int courseNumber;

};

#endif // STUDENT_H
