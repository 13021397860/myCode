#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"


class ObligatoryCourse: public Course
{
    public:
        ObligatoryCourse(int ch=0,string nam="self-taught Class",int m=0);
        virtual ~ObligatoryCourse();
        void setscore(int);
        int getscore();
       void toString()
        {
            cout<<name<<" "<<creditHour<<" "<<getscore();
        }
    protected:
    private:
        int score;
};

#endif // OBLIGATORYCOURSE_H
