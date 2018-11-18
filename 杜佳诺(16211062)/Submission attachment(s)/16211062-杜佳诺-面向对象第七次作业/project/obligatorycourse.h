#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse( string, int , int = -1, double =0.6 );
        virtual ~ObligatoryCourse();

        virtual void setGrade( int );
        virtual int getScore() const ;
        virtual double getWeight() const ;

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
