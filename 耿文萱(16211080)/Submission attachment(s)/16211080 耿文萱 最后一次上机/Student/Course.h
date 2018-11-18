#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;


class Course
{
    public:
        Course(const string &,const int );
        friend ostream& operator << (ostream&,const Course&);
        string getCourse()const;
        void setAll(const string &,const int );
        int getCreditHour()const;
        virtual ~Course();
        virtual void print1(){};
        virtual void setGrade(const int,const char){};
        virtual int getScore()const=0;
        virtual int getO() const{ return creditHour;};
	    virtual int getE() const  {return 1;};

    protected:
    private:
         string name;
         int creditHour;
};

#endif // COURSE_H
