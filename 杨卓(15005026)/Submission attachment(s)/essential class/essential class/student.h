#ifndef STUDENT _H
#define STUDENT _H
#define MAX_SIZE 12
#include "date.h"
#include "Course.h"
class student
{
    public:
        static int count;
        student ();
        student(const student & );
        student(char *,int ,int ,int );
        void setbirthdy(int y,int m,int d);
        virtual ~student ();
        void printUniversal();
        void printStandard();
        void setBirthday(int,int,int);
        void setName(char* );
        char* getName() const;
        int getYear();
        int getMonth();
        Date getBirthday() const;
        void printName();
        void cheakName();
        void printBirthday();
        int getnum();
        student& addCourse(Course *course);
        student& addCourse(const string &courseName, int creditHour);
        void printcourseList(int);
        bool removeCourse(int);
        friend ostream& operator << (ostream &,const student &);
        float calcCredit();
        virtual int getElectiveCoursenum(){}
        virtual int getsum(){}
        bool savefile1(student &);
        bool readfiile1(student &);
    protected:


    private:
        char *name;
        int year;
        int month;
        int day;
        Date birthday;
        Course *courseList[MAX_SIZE];
        int courseNumber;




};

#endif // STUDENT _H
