#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "course.h"
#include <iostream>
#include <string>
using namespace std;
using std::ostream;
using std::istream;
class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string n,const int c,const int = 0);
        virtual ~ObligatoryCourse();
        ObligatoryCourse(const ObligatoryCourse &o);
        void setmark(const int );
        int getmark()const;
        void print()const;

        virtual int getScore() const;
        virtual int getElectiveNumber() const ;
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
