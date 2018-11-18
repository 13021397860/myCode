#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string s, const int h, const int m = 0);
        virtual ~ObligatoryCourse();
        int setMark(const int m);
        virtual int getScore()const;
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
