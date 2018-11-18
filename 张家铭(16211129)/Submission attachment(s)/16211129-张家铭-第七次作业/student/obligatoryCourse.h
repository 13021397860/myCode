#ifndef OBLIGATORYCOURSE_H_INCLUDED
#define OBLIGATORYCOURSE_H_INCLUDED
#include "course.h"
class obligatoryCourse:public course
{
private:
    int mark;
public:
    obligatoryCourse();
    obligatoryCourse(const string ,const int );
    void setMark(const int );
    int getScore();
};

#endif // OBLIGATORYCOURSE_H_INCLUDED
