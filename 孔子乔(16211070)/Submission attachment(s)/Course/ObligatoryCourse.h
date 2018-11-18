#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const int _mark);
        ObligatoryCourse(const ObligatoryCourse &another);

        void setmark(const int _mark);
        int getmark()const;
        virtual int getscore()const;

        ~ObligatoryCourse();
    private:
        int Mark;
};

#endif // OBLIGATORYCOURSE_H
