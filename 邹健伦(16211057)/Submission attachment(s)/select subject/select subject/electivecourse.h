#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "course.h"
#include<iostream>
using namespace std;


class electivecourse : public course
{
    public:
        electivecourse(const string &,const int &);//name credit grade
        electivecourse(const electivecourse &);
        void setgrade(const char &);
        int getscore()const;
        friend ostream& operator<<(ostream& ,const electivecourse &);

        virtual ~electivecourse();

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
