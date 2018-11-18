#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10

#include "Date.h"
#include"course.h"
#include<string>
using namespace std;
class student
{
    static int count;
    public:
        student(const char*const ,const int &,const int &,const int &);//name birth
        student(const student &);
        virtual ~student();
        void setname(const char*const );
        void setdate(const int&,const int&,const int&);
        char*getname()const;
        int getyear()const;
        int getmonth()const;
        int getday()const;
        void nextday();
        static int geti(){return count;};
        student& addcourse(const string &,int);
        student& addcourse(course*course);
        friend ostream& operator<<(ostream& ,const student &);
        int getcoursenumber()const{return coursenumber;};
        course& getcourse(int)const;
        bool removecourse(int i);
        void calculate();
        double getcalc();
        void print()const;
    protected:

    private:
        char*name;
        Date birthdate;
        course*courselist[MAX_SIZE];
        int coursenumber;
        double calccredit;

};

#endif // STUDENT_H
