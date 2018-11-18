#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string n="", const int ch=0):Course(n, ch){}
        void setMark(const int);
        virtual int getScore() const;
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
