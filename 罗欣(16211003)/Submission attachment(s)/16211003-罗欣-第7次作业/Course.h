#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
using namespace std;


class Course
{
    public:
        Course();
        virtual ~Course();
        void setname(string);
        string getname();
        void setcreditHour(int);
        int getcreditHour();
        virtual void setmark(const int);
        virtual int getScore()const=0;
        friend ostream& operator<<(ostream& cout,const Course&);

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
