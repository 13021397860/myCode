#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(string="NULL",int=0,int=0);
        void setScore(int);
        int getScore()const;
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
