#ifndef TEXTSTUDENTCLASS_H
#define TEXTSTUDENTCLASS_H

#define MAX_SIZE 20

#include "Date.h"
#include<iostream>
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<typeinfo>
class TextStudentClass
{
    public:
        TextStudentClass(char* N,const Date &birth);
        TextStudentClass();
        TextStudentClass(const TextStudentClass &);
        virtual ~TextStudentClass();

        friend ostream &operator<<(ostream &,const TextStudentClass &);

        void Setstudentname(char* N);
        char *Getname()const;
        void Printinformation();
        Date Getbirth() const;
        void Getstudentnumber();
        bool removeCourse(int i);
        string Getcou(int );
        int getcoursenumber(){return courseNumber;};
        Course *getcourse(int i){return courseList[i];};
        void calcCredit();
        int getsumcreditO();
        int getsumcreditE();
        int getsumpeoE();
        int getcourseList(int i,Course *&temp);


        TextStudentClass& addCourse(const std::string &courseName,int creditHour,int );
        TextStudentClass& addCourse(const std::string &courseName,int creditHour,char );


    protected:

    private:
        char* name = NULL;
        const Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber = 0;
        int gra;



};
#endif // TEXTSTUDENTCLASS_H
