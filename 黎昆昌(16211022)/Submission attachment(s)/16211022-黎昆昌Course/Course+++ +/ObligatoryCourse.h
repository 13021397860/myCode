#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string="math",const int=4,const int=0);
        virtual ~ObligatoryCourse();
        virtual void setScore(const int &);
        virtual int getScore() const;

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
