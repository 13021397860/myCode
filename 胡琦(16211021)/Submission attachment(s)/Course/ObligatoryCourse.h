#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        void setScore(const int);
        int getScore()const{return mark;}
        virtual ~ObligatoryCourse();
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
