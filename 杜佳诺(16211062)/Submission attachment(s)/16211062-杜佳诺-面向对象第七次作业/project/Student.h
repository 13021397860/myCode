#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "course.h"
#define MAX_SIZE 99
#include <iostream>
using namespace std;

class Student
{
    friend ostream &operator<<( ostream& , const Student& );

    public:
        Student( const char* , const Date* );
        Student( const Student& );
        virtual ~Student();

        void setName( const char* );

        char* getName() const;
        Date  getBirthDate() const;

        int getCount();
        int getCourseNumber();

        Student& addCourse( Course* );
        //Student& addCourse( const string&, int );

        bool courseExist( int, string& );
        bool removeCourse( int );
        void setGrade( int );

        bool judgeCourse( int );
        string getCourseName( int );

        double caleCredit();

        void VisitCourseList( int );

    protected:

    private:
        char* name;
        const Date birthDate;
        static int Count;

        Course *courseList[MAX_SIZE];
        int courseNumber;

};

#endif // STUDENT_H
