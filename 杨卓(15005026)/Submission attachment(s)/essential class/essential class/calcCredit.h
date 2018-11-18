#ifndef CALCCREDIT_H
#define CALCCREDIT_H
#include "Course.h"


class calcCredit public Course
{
    public:
        calcCredit();
        virtual ~calcCredit();
        virtual int getgradepoint(){}
        virtual int getsum() {}
    protected:

    private:
        int gradepoint;
};

#endif // CALCCREDIT_H
