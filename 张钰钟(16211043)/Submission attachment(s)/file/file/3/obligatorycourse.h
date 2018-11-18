#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        virtual ~ObligatoryCourse();
        virtual void setMark(const int);
        int getScore();
        void setCreditCard(const int);
        void setName(const string &s);
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
