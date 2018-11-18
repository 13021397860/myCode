#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
class ObligatoryCourse : public Course
{

    public:
        ObligatoryCourse();
        ObligatoryCourse(int x);
        virtual int getScore()const;
        virtual void setGrade(int x);
        virtual int who();
    protected:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
