#define MAX_SIZE 10
#ifndef STUDENT_H
#define STUDENT_H

#include <typeinfo>
#include "Date.h"
#include "Course.h"
#include "electivecourse.h"
#include "Obligatorycourse.h"


class Student
{
    public:
        Student();
        Student(const Student&);
        Student(const char*,const int,const int,const int);
        ~Student();
        char* getStudentName();
        Date getBirthday();
        void setName(char*);
        static void getStudentCount();
        Student& addCourse(Course *course);
        //Student& addCourse(const string &courseName, int creditHour);
        void printcourselist();
        bool removeCourse(int);
        friend ostream& operator<<(ostream&, const Student&);
        bool setCourseScore();
        double calcCredit() const;

    private:
        char* name;
        const Date birthdate;
        static int StudentCount;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STUDENT_H
