#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
      ObligatoryCourse(const string na="Empty",const int credit=0):Course(na,credit)
        {
            setmark(0);
        }
        virtual ~ObligatoryCourse();
        int getmark();
        void setmark(const int m);
        virtual int getScore()const;
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
