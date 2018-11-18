#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(const string  ,int ,int);
        ObligatoryCourse(const ObligatoryCourse &);
        ObligatoryCourse(const string  ,int);
        virtual ~ObligatoryCourse();

        bool setMark(int );
        int getScore() const;

        virtual int getElectiveNumber() const {return 0;}
        virtual double getWeight() const {return 0.6;}

    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
