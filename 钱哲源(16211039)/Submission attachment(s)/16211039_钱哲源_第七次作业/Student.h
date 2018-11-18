#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 15
#include "Date.h"
#include "Course.h"

class Student
{
    friend ostream& operator<<(ostream&, const Student&);
    friend ostream& operator<<(ostream&, const Course&);
    friend class Console;
    public:
        double calcGPA() const;
        static int countStudent(){return count;};
        Student(const char *n="",const int =1,const int =1,const int =1);
        Student(const Student& n, const Date& d);
        const char* getStudentName() const;
        Student& setName (const char* const n);
        void getBirthDate() const;
        int getY() const{return birthDate.year;};
        int getM() const{return birthDate.month;};
        int getD() const{return birthDate.day;};
        Student& addCourse(Course *course);
        bool setCourseScore();
        bool removeCourse(int );
        virtual ~Student();
    protected:

    private:
        int calcObligatoryCredit() const;
        int calcElectiveNumber() const;
        char *name;
        const Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STUDENT_H

