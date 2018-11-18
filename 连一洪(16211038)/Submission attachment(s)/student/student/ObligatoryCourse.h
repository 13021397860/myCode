#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include <typeinfo>
#include "Course.h"
#include <iostream>
#include <cstring>

using namespace std;
using std::ostream;
class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string na, const int cr);
        virtual ~ObligatoryCourse();
        virtual int getscore()const;
        void setMark(const int ma);
        int getScore()const;

    protected:
    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
