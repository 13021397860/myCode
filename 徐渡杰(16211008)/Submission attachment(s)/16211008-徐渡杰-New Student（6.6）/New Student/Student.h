#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 12
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <fstream>
class Student
{
    public:
        static int Count;
        Student();
        Student(const Student &student);
        virtual ~Student();

        void setStudentName(char *n);
        void setStudentBirth(int y,int m,int d);
        int getStudentCount();
        string getStudentName();
        Date getStudentBirthday();
        Student &addCourse(Course* course);
        bool removeCourse(int i);
        string getConsultCourseName(int i);
        double consultCourse(int i);
        double calcCredit();
        int getcourseNum();
        void print();
        friend ostream& operator<<(ostream &out,Student &student);
        Course *courseList[MAX_SIZE];
    protected:

    private:
        char *name;
        Date birthDate;

        int courseNum;
};

#endif // STUDENT_H
