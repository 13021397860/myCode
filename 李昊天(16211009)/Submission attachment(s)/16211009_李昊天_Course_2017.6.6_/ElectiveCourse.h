#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
using namespace std;
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(){};
        ElectiveCourse(const string &na, const int &cre, char gra) : Course(na,cre){setGrade(gra);}
        virtual ~ElectiveCourse();
        void setGrade(char);
        virtual int getScore();
    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
