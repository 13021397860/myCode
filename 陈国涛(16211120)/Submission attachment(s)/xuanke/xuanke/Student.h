#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Obligatory.h"
#include "ElectiveCourse.h"
#include <iostream>
#define MAX_SIZE 21
using namespace std;
class Student
{
    friend ostream &operator<<(ostream &output, const  Student&);
    public:
        Student ();
        Student (const Student&);
        Student (const char* newname, const int y,const int m, const int d);
        Student &addCourse(Course *course, const int CourseType);

        void setStuScore(const int coursetype , const int score, const int ncourse);
        int GetbirthDate() const;
        static int GetCount();
        const int GetCoursenumber();
        void SetName(const char *newname);

        float calcCredit() const;
        bool removeCourse(const int );

        virtual ~Student();
    protected:
        char *name;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        const Date birthDate;
        static int count ;
    private:



};

#endif // STUDENT_H
