#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include"Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const char &,const string &,int);
        void setScore(int ,const char& );
        virtual int getScore()const;
        int  print()const;

        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;

};

#endif // ELECTIVECOURSE_H
