#ifndef STUDENT _H
#define STUDENT _H
#include "date.h"

class student
{
    public:
        student ();
        virtual ~student ();
        void printUniversal();
        void printStandard();
        void setBrithday(int,int,int);
        void setName(char* );
        char getName(return name);
        int getYear(){return year;}
        int getMonth(){return month;}
        int getDay(){return day;}
        void printName();
        void cheakName;


    protected:
        char *name;
        int year;
        int month;
        int day;

    private:
};

#endif // STUDENT _H
