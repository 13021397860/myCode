#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
#include "MyException.h"
using namespace std;
class Course
{
    public:
        Course();
        Course(const string s, const int h);
        virtual ~Course();
        int setCourse(const string s, const int h);
        int getCourse(string &s, int &h)const;
        virtual int getScore()const = 0;
    friend ostream& operator <<(ostream &, const Course&);
    protected:
        string name;
        int creditHour;
};

#endif // COURSE_H
