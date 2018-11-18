#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>

using namespace std;

class Course
{
    public:
        Course(const string ="NoCourse",const int =0);
        Course(const Course& other);
        void setCourse(const string ="NoCourse",const int =0);
        string getName()const;
        int getCredit()const;
        virtual int getScore()const=0;
        friend ostream &operator<<(ostream &,const Course *);
        virtual ~Course();

    protected:
        string name;
        int creditHour;

    private:

};

#endif // COURSE_H
