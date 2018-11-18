#ifndef COURSE_H
#define COURSE_H
#include<bits/stdc++.h>
using namespace std;

class Course
{
    public:

        friend ostream& operator<<(ostream&,const Course&);

		friend class Student;

		Course();

        Course(string&,int&);

        Course(Course&);

        virtual ~Course();

        void setname(string);

        void setcreditHour(int);

        string getname();

        int getcreditHour();

        virtual int getScore()=0;

        virtual int setScore(int);

		virtual int setScore(char);

    protected:
        string name;

        int creditHour;

    private:
};

ostream& operator<<(Course&,ostream);

#endif // COURSE_H
