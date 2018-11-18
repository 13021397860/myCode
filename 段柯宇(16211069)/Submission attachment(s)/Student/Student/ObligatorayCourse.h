#ifndef OBLIGATORAYCOURSE_H
#define OBLIGATORAYCOURSE_H

#include "Course.h"


class ObligatorayCourse : public Course
{
    public:
        ObligatorayCourse(const string _name,int _creditHour);
        virtual ~ObligatorayCourse();
        virtual int getscore() const;
        int setgrade(int);


    protected:
        int mark;

    private:
};

#endif // OBLIGATORAYCOURSE_H
