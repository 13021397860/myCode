#include "Course.h"
#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const string, const int, const int);
        ObligatoryCourse(const ObligatoryCourse &);
        virtual ~ObligatoryCourse();
        void setScore(const int);
        virtual const int getScore() const;
        virtual void getScore(int &) const;

        //重载 <<
        //friend ostream& operator <<(ostream &os, const ObligatoryCourse &c);
    protected:

    private:
        int mark; //³É¼¨
};

#endif // OBLIGATORYCOURSE_H
