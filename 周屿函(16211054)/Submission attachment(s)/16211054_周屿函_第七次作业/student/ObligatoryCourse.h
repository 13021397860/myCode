#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Exception.h"
#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        virtual ~ObligatoryCourse();
        ObligatoryCourse(const string a,int x,int t)
            :Course(a,x),mark(t){};
        ObligatoryCourse(const ObligatoryCourse& x)
            :Course(x),mark(x.mark){};
        void setScore(int x)
        {
            if(x>=0&&x<=100)
                mark=x;
            else
                throw Exception(Grade_Invalid);
        }
        virtual int getScore(){return mark;}
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
