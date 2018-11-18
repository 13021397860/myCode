#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

#define MAX_SIZE 20

class Student
{
    public:
        Student(const char* name = "Estatew");
        virtual ~Student();
        Student(const Student &);
        void SetName(const char *n);
        void SetBirthday(Date *bd);
        char *GetName(void);
        Date &GetBirthday(void);
        void print();
        Student& addCourse(Course *);
        static int count;
        friend ostream& operator << (ostream&,Student&);
        bool removeCourse(int);
        void setScore(int, int);
        void calcCredit(); 
        

    private:
        char* name;
        Date *birthDay;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        double qz1,qz2;
        double r1,r2;
};


#endif // STUDENT_H
