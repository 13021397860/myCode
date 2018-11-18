#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#define MAX_SIZE 20
#include <string>
#include "MyException.h"
class Student
{
    public:
        Student();
        Student(const Student&);
        Student(const char*_name);
        Student(const char*_name,const Date&_birthDate);
        bool setName(const char* _name);
        char* getName();
        bool getName(char*const pos);
        Date getBirthday()const;
        bool printName()const;
        void printBirthday()const;
        void print()const;
        static int getStudentNum();
        static void printStudentNum();
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName, int creditHour);
        bool removeCourse(int i);
        bool setCourseScore(int i) throw(MyException);
        int getCourseScore(int i)const throw(MyException);
        double calcCredit()const;
        friend ostream &operator <<(ostream &out,const Student &A);
        virtual ~Student();
    protected:
    private:
        char *name;
        const Date birthDate;
        int courseNumber;
        Course *courseList[MAX_SIZE];
        static int count;
};

#endif // STUDENT_H
