#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include <string>
using namespace std;
class ObligatoryCourse:public  Course
{
    public:
        ObligatoryCourse(const string &n="Mathmatic",int ch=0, int m=0);
        void setscore(int);
        int getscore();
        void printobliga();
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H

