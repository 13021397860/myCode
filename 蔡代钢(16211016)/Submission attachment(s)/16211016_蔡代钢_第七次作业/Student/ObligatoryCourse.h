#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include "MyException.h"
class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(string ,double, double);
        virtual ~ObligatoryCourse();
        void setall(string ,double, double);
        void setScore(double );
        double getScore();
    protected:
    private:
        double mark;
};

#endif // OBLIGATORYCOURSE_H
