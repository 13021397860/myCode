#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "course.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse( string, int, char = 'F', double = 0.4 );
        virtual ~ElectiveCourse();

        virtual void setGrade( int );
        virtual int getScore() const ;
        virtual double getWeight() const ;

    protected:

    private:
        char grade;

};

#endif // ELECTIVECOURSE_H
