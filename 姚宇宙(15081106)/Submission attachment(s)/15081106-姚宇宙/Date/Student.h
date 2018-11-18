#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#define MAX_SIZE 100
#define CREDITOBLIGATORY 0.6
#define CREDITELECTIVE 0.4

class Student
{
    public:
        Student();
        Student(const char *, int, int, int);
        Student(const char *, const Date &);
        Student(const Student &);
        virtual ~Student();
        char* getName() const;
        Date getBirthDate() const;
        void setName(const char *);
        void setBirthDate(int, int, int);
        void setBirthDate(const Date &);
        void print() const;
        static int getStudentCount();
        Student& addCourse(const Course *);
        Student& addCourse(const std::string &, int, bool = true);
        bool removeCourse(int);
        void printCourseList() const;
        int getCourseNumber() const;
        friend std::ostream& operator << (std::ostream &, const Student &);
        friend std::ofstream& operator << (std::ofstream &, const Student &);
        Student& setCourseScore(int, int);
        double calcCredit() const;
    private:
        char *name;
        Date birthDate;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        static int count;
};

#endif // STUDENT_H
