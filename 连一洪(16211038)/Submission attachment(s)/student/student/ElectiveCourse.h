#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include <typeinfo>
#include "Course.h"
#include "MyException.h"
#include <iostream>
#include <cstring>

using namespace std;
using std::ostream;
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string na, const int cr);
        virtual ~ElectiveCourse();
        virtual int getscore()const;
        void setGrade(const char cla);
        int getScore()const;
    protected:
    private:
        char grade;

};

#endif // ELECTIVECOURSE_H
