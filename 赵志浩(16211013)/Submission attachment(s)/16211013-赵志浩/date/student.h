#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 100
#include <iostream>
#include "date.h"
#include <string>
#include "course.h"
#include "electivecourse.h"
#include "obligatorycourse.h"
#include <iomanip>
using namespace std;
class student
{
    public:
        student();
        student(student&);
        virtual ~student();
        string getname() const {return name;};
        int getBirthDay()   {return birthDate.getDay();};
        int getBirthMonth() {return birthDate.getMonth();};
        int getBirthYear()  {return birthDate.getYear();};
        static int getAmount() {return amount;};
        int getCourseNumber() const {return courseNumber;};
        bool setName(const string);
        bool setBirthDate(int,int,int);
        void printBirth(){cout<<birthDate;return;};
        void printName()    {cout<<name<<endl;return;};
        bool setScore(int,int);
        student& addCourse(Course*);
        student& addObligatoryCourse(const string&,int);
        student& addElectiveCourse(const string&,int);
        friend ostream& operator << (ostream& out,const student& s)
        {
            out<<"name:"<<s.getname()<<" birth date:"<<s.birthDate<<" course information:"<<endl;
            for (int i=0;i<s.courseNumber;i++)
            {
                out<<"course "<<i+1<<":"<<*(s.CourseList[i])<<endl;
            }
            out<<"grade point: ";
            out<<setprecision(2)<<s.calcCredit()<<endl;
            return out;
        }
        bool removeCourse(int);
        double calcCredit() const;
    protected:
    private:
        Course *CourseList[MAX_SIZE];
        int courseNumber;
        date birthDate;
        string name;
        static int amount;
};

#endif // STUDENT_H
