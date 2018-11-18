#ifndef COURSE_H
#define COURSE_H
#include<iostream>
using namespace std;
class Course
{
    public:
        Course();
        virtual ~Course();
        string getName();
        int getCreditHour();
        void setName(const string &s);
        void setCreditCard(const int);
        virtual void setMark(const int);
        virtual void setGrade(const char);
        virtual int getScore()=0;

    protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
