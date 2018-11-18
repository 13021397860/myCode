#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course
{
    friend ostream& operator<<(ostream &, const Course&);
    public:

        virtual int getScore() const=0;
        virtual double getWeight() const=0;

        virtual int getObligatoryCredit() const { return creditHour;}
        virtual int getElectiveNumber() const {return 1;}

        const string& getName()	const	{return name;}
        void setName(const string &n)	{name=n;}
        int getCreditHour()	const	{return creditHour;}
        void setCreditHour(int ch){creditHour=ch;}

        Course(const string &n="", int ch=0);
        virtual~Course();
    protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
