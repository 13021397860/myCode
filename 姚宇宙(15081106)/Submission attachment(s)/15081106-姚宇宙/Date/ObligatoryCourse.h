#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include<iostream>

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(std::string, int, int = 0);
        ObligatoryCourse(const ObligatoryCourse&);
        virtual ~ObligatoryCourse();
        virtual int getScore() const;
        virtual void setScore(int);
        virtual bool testObligatory() const;
    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
