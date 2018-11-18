#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Exception.h"

#define MAX_COURSE 16

class Student
{
    public:
        Student();
        Student(const char* const);
        Student(const int&, const int&, const int&);
        Student(const char* const, const int&, const int&, const int&);
        Student(const char* const, const Date&);
        Student(const Date&);
        Student(const Student&);
        virtual ~Student();

        friend std::istream& operator >>(std::istream&, Student&);
        friend std::ostream& operator <<(std::ostream&, const Student&);

        friend class Engine;

        void setBirthDate(const Date&);
        void setBirthDate(const int&, const int&, const int&);
        void setName(const char* const);
//        bool setScore(const int&, int);

        Date getBirthDate() const;
        char* getName() const;
        int getCourseNumber() const;
        static int getCounter();

        Student& addCourse(Course*); //throw(Course_List_Full_Exception,Course_Existent_Exception);
//        Student& addCourse(const std::string&, const int&, const bool&);
        bool removeCourse(int); //throw(Course_List_Empty_Exception);

        double calcCredit() const;

    private:
        char* name;
        Date birthDate;
        Course* courseList[MAX_COURSE];
        int courseNumber;
        static int counter;
};

#endif // STUDENT_H
