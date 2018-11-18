#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include<string>
using namespace std;
class ElectiveCourse : public Course
{
    public:
        virtual int getScore() const;
        ElectiveCourse(const string s, int hour, char g = '\0'):Course(s, hour),grade(g){};
        void setGrade(const char s);
        const int getGrade()const;
        virtual ~ElectiveCourse();
        void print()const;

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
