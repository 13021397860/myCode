#ifndef COURSE_H
#define COURSE_H
#include"Course.h"
#include<iostream>
using namespace std;

class Course
{
    friend ostream& operator<<(ostream&out,const Course &c)
    {
        out<<"name: <"<<c.getName()<<"> credit: <"<<c.getCreditHour()<<"> score: <"<<c.getScore()<<">"<<endl;
    }
    public:
        Course(string="NULL",int=0);
        void setName(string);
        void setCreditHour(int);
        string getName()const;
        int getCreditHour()const;

        virtual void setScore(int);
        virtual int getScore()const=0;
        virtual ~Course();

    protected:

    private:
        string name;
        int creditHour;
        int score;
};

#endif // COURSE_H
