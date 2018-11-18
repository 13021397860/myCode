#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
using namespace std;
class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string &names,const int &credit,char grades):Course(names,credit){setgrade(grades);}
        virtual ~ElectiveCourse();
        void setgrade(char);
        virtual int getScore() const;


    protected:

    private:
        char grade;


};

#endif // ELECTIVECOURSE_H
