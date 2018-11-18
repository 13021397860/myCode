#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include <string>
#include"MyException.h"
using namespace std;

class Course
{
    public:
        Course();
        Course(string _name,int _creditHour);
        virtual ~Course();
        void setName(string _name);
        string getName() const;
        void setcreditHour(int _creditHour);
        int getcreditHour() const;
        friend ostream & operator <<(ostream&os,const Course& c);
        void SetMark();
        virtual int getScore() const =0;

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
