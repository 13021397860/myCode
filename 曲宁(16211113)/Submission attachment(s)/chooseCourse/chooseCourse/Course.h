#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<string>
using namespace std;

class Course
{
    public:
        friend ostream &operator<<(ostream &,const Course &);
        virtual int print()const{};
        Course(const string& ,int = 1);
        void setCoursename(const string & );
        string getcourseName()const;
        void setHour(int );
        int getHour()const;
        string courseName;
        int creditHour;
        virtual  void setScore(int ,char){};

        virtual int getScore()const=0;
        virtual ~Course();
    protected:

    private:

};

#endif // COURSE_H
