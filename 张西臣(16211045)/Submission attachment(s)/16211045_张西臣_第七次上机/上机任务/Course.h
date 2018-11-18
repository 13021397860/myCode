#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course
{
    friend ostream&  operator <<(ostream&, const Course &c);
    public:
        Course(const string ="Empty",const int=0);
        virtual ~Course();
         string getcoursename() const ;
         int getcreditHour() const;
        void setcoursename(const string );
        void setcreditHour(const int );
        virtual int getScore()const =0;
    private:
        string name;
        int creditHour;

};

#endif // COURSE_H
