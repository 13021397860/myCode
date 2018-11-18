#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "course.h"
#include "myexception.h"
class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(string="",int=0,int=0);
        ObligatoryCourse(const ObligatoryCourse &);
        int getScore(){return mark;};
        void setScore(int m){this->mark=m;return;};
        virtual ~ObligatoryCourse();
    protected:
        int mark;
    private:
};

#endif // OBLIGATORYCOURSE_H
