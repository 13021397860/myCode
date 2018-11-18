#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include"course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include"Date.h"
#define Max_size 20
class Student
{
    friend ostream &operator<<(ostream &,const Student&);
    public:

        Student();
        Student(int ,int ,int ,const char* );
        Student(const Student &);
        void setYear(int );
        void setMonth(int );
        void setDay(int );
        virtual ~Student();
        void setName(const char *);
        char *getName()const;
        Date getBirthDate()const;
        void printStu()const;
        static void printCnt();
        Student& addCourse1(const string &courseNa,int creditHour,int m);
        Student& addCourse2(const string& courseNa,int creditH,char g);
        Student& addCourse3(course *course_);
        bool removeCourse(int ) ;
        void  WriteCJ();
        void   calcCredit() ;
        void setJidian(int );
        int getJidian() const;
        int GradeOc(int);
        char GradeEc(char);
    private:
        char *name ;
        const Date birthDate;
        static int cnt;
        course *courseList[Max_size];//Ҫnew
        int courseNumber;
        int jidian;
};

#endif // DATE_H_INCLUDED
