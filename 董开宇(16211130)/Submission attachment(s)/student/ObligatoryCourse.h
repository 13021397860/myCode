#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(int);
        void setMark(const int);
        int getScore();
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
