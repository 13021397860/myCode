#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        void setmark(const int);
        virtual int getScore() const;

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
