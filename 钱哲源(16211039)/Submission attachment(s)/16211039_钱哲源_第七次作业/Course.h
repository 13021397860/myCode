#ifndef COURSE_H
#define COURSE_H
#include<iostream>
using namespace std;
#include<cstring>

class Course
{
    friend ostream& operator<<(ostream&, const Course*);
    friend class Student;
    public:
        virtual int getScore() const=0;
        Course();
        Course(const string n, int h);
        string getName()const;
        int getHour()const;
        void setName (const string n);
        void setHour (int h);
        void printx() const;
        virtual ~Course();

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H

