#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(){mark=0;}

        ObligatoryCourse( string , int , int );

        int getScore()const;

        void setScore( int );

        string toString() const;

        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
