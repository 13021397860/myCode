#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(const string &,int,int=-1);
        void setScore(const int&);
        int getScore()const;
        bool is_haveScore()const;
    //protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
