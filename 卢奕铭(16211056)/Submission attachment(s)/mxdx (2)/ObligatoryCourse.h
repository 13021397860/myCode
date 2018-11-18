#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<string>
#include "Course.h"

using namespace std;
class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string s, const int h, const int m = 0);
        virtual ~ObligatoryCourse();
        int setMark(const int m);
        int getScore()const;
    private:
        int mark=0;
};

#endif // OBLIGATORYCOURSE_H
