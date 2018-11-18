#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include"Course.h"


class ObligatoryCourse: public Course
{
    public:
        ObligatoryCourse();
        virtual ~ObligatoryCourse();
        void setmark(const int);
        int getScore()const;


    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
