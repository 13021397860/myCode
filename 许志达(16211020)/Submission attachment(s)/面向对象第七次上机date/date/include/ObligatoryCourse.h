#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<string>
#include"Course.h"
using namespace std;
class ObligatoryCourse :public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string &,int =2,int =80);
        void setmark(int);
         int getScore();
        void print()const;
        void setCourse(const string &,int);
        virtual ~ObligatoryCourse();

    protected:
            int mark;
    private:

};

#endif // OBLIGATORYCOURSE_H
