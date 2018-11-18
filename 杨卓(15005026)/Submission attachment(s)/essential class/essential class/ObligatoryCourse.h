#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse:public Course
{
public:
    ObligatoryCourse();
    ObligatoryCourse(const string &names,const int &credit,char marks):Course(names,credit)
    {
        setmark(marks);
    }
    virtual ~ObligatoryCourse();
    void setmark(int);
    virtual int getScore() const
    {
        return mark;
    }


protected:

private:
    int mark;

};

#endif // OBLIGATORYCOURSE_H
