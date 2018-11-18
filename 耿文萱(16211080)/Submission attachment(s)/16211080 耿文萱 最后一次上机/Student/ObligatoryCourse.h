#include "Course.h"
#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include <string>
using namespace std;

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse(const string &,const int ,const int=0);
        void setGrade(const int ,const char);
        virtual int getScore()const;
        void print1();
        virtual int getE() const {return 0;}
        virtual ~ObligatoryCourse();
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
