#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "course.h"
#include <iostream>
#include <string>
using namespace std;
using std::ostream;
using std::istream;
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(string n,int c,char g ='0');
        virtual ~ElectiveCourse();
        ElectiveCourse(const  ElectiveCourse &e);
        void setgrade(char );
        int getgrade()const;
        void print()const;

        virtual int getScore() const;
        virtual int getObligatoryCredit() const;
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
