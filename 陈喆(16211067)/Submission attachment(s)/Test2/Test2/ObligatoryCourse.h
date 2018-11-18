#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string ="untitled",const int =0);
        ObligatoryCourse(ObligatoryCourse&);
        virtual ~ObligatoryCourse();
        void SetMark(const int);
        virtual int getScore();
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
