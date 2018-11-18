#ifndef STUDENT_H
#define STUDENT_H


#include "Date.h"
#include "Course.h"
#include <iostream>

#define MAX_SIZE 10
#include "OutArray.h"

using namespace std;

class Student
{
    public:
        Student();
        Student( const char *na, const Date &birth );
        Student( const Student &stu );
        virtual ~Student();
        //
        char *getName()const;
        Date getBirth()const;
        static int getCount();
        //
        Student &addCourse( Course *course );
        Student &addCourse( const string &courseName, int creditHour );
        int getCourseNumber()const;
        Course *getCourse( int i )const;
        //
        friend ostream& operator<<( ostream &, Student & );
        //
        void removeCourse( int i );
        //
        double calcCredit();

    protected:

    private:
        char *name = NULL;
        const Date birthDate;
        static int stu_count;
        Course *courseList[ MAX_SIZE ];
        int courseNumber;
};

#endif // STUDENT_H
