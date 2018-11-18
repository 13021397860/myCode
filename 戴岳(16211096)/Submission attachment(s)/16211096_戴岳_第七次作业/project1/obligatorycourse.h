#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"course.h"

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string ,const int);
        ObligatoryCourse(const string ,const int,int );

        void setScore(int);
        int getScore()const;



        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
