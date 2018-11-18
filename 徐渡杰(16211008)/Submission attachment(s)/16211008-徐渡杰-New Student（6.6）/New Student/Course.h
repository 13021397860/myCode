#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>
using namespace std;

class Course
{
    public:
        Course(string = "none",double = 0,int = 0);
        virtual ~Course();
        virtual void setScore(double m){}
        virtual void setScore(char s){}
        virtual double getScore()=0;
        void setCourseName(string A);
        void setCourseCredit(double cH);
        string getCourseName();
        double getCourseCredit();
        int Tag(){return tag;}
        friend ostream& operator<<(ostream &out,Course &course);
    protected:
        string name;
        double creditHour;
        int tag;
    private:

};

#endif // COURSE_H
