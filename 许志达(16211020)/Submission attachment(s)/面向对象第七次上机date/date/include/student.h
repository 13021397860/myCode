#ifndef STUDENT_H
#define STUDENT_H
#include"date.h"
#include"Course.h"
#define MAX_SIZE 20
class student
{
    public:
        friend ostream &operator <<(ostream &,const student &);
        student(const char *const,int = 1998,int = 10,int = 25);
        student(const student&);
        char *getname();
        date getbirthdate();
        void setname(char*);
        void setbirthdate(int ,int ,int);
        bool removeCourse(int);
        //double gpa;
        //void print();
        double calcCredit();
        virtual ~student();
        static int getcount();
        student& addCourse(Course *);
        student& addCourse(const string &,int );
    protected:

    private:
        char *name;
        date birthdate;
        static int Count;
        Course *courseList[MAX_SIZE];
        int courseNumber;

};

#endif // STUDENT_H
