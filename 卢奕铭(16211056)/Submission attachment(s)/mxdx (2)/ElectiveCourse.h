#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<string>
#include "Course.h"

using namespace std;
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string s, const int h, const char c = 'F');
        virtual ~ElectiveCourse();
        int setGrade(const char c);
        int getScore()const;

    private:
        char grade='F';
};

#endif // ELECTIVECOURSE_H
