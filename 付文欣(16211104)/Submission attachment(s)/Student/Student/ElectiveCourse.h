#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse:public Course
{
    public:
        ElectiveCourse(const string &,int,const char ='0');
        void setScore(const char &);
        int getScore()const;
        bool is_haveScore()const;
    //protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
