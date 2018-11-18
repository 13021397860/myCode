#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<iostream>
using namespace std;
class course
{
    public:
        course();
        course(const string &,const int &);
        //course(const course &);
        void setname(const string &);
        void setcred(const int &);
        string getname()const{return name;};
        int getcred()const{return creditHour;};
        friend ostream& operator<<(ostream& ,const course &);
        virtual ~course();
        virtual int getscore()const=0;

    protected:
        string name;
        int creditHour;

    private:

};

#endif // COURSE_H
