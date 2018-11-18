#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(){};
        ObligatoryCourse(const string &na, const int &cre, int ma) : Course(na,cre){
            setMark(ma);
        };
        virtual ~ObligatoryCourse();
        void setMark(int);
        virtual int getScore() {return mark;}
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
