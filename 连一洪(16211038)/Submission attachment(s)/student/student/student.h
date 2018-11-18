#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include "Course.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
using std::ostream;
class Student
{
    friend ostream& operator<<(ostream& , const Student&);
    public:
        Course *courseList[Total_Num];
        Student();
        Student(const Student &a);
        virtual ~Student();

    public:

        int coursenumber;
        string getName()const;
        int getbirthdateYear()const;
        int getbirthdateMonth()const;
        int getbirthdateDay()const;
        int getcoursenumber()const;
        void setcoursenumber();
        void setName(const string Barry);
        void setbirthdate(const int,const int,const int);
        void printStudent()const;
        static int getCounter();
        Student& addCourse(Course* );
        Student& addCourse2(const string &courseName, int );
        bool removeCourse(int );
        bool setCourseScore(int );
        int totalObCreditHour();
        int totalElCourseNumber();
        int sumObliCourse();
        int sumElecCourse();
        float calcCredit();//¼¨µã³É¼¨

    protected:
    private:
        static int counter;
        string name;
        Date birthdate;



};

#endif // STUDENT_H
