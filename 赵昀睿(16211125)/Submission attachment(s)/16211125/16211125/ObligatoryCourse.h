#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include "IllegalGrade.h"

class ObligatoryCourse:public Course
{
    public:
    //    ObligatoryCourse();
        ObligatoryCourse(string,int,int);
        //ObligatoryCourse(  );
        virtual ~ObligatoryCourse();
        //
        void setMark(int m);
        int getScore()const;
        void printScore()const;

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
