#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include"MyException.h"
using namespace std;
using std::cout;
using std::endl;
class Course
{
    public:
        Course();
        Course(std::string ,int );
        virtual const void print(){};

        friend ostream &operator<<(ostream &,const Course &);

        virtual ~Course();
        void Setcourse(std::string,int);
        void Getcourse();
        virtual void SetGrade( char ){};
        virtual void SetMark( int ){};
        virtual int Getscore()const=0;
        int GetcreditHour();

    protected:

    private:
        std::string name;
        int creditHour;
};

#endif // COURSE_H
