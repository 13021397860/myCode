#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(string="NULL",int=0,char='\0');
        void setScore(char);
        int getScore()const;
        virtual ~ElectiveCourse();

    protected:

    private:
        int grade;
};

#endif // ELECTIVECOURSE_H
